class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> cost(n - x + 1);
        multiset<int> low, high;
        long long sumLow = 0, sumHigh = 0;
        auto rebalance = [&]() {
            while (low.size() > high.size() + 1) {
                auto it = prev(low.end());
                int val = *it;

                low.erase(it);
                sumLow -= val;

                high.insert(val);
                sumHigh += val;
            }

            while (low.size() < high.size()) {
                auto it = high.begin();
                int val = *it;

                high.erase(it);
                sumHigh -= val;

                low.insert(val);
                sumLow += val;
            }
        };

        auto add = [&](int val) {
            if (low.empty() || val <= *prev(low.end())) {
                low.insert(val);
                sumLow += val;
            } else {
                high.insert(val);
                sumHigh += val;
            }

            rebalance();
        };

        auto remove = [&](int val) {
            auto it = low.find(val);

            if (it != low.end()) {
                low.erase(it);
                sumLow -= val;
            } else {
                it = high.find(val);
                high.erase(it);
                sumHigh -= val;
            }

            rebalance();
        };
        auto getCost = [&]() -> long long {
            long long median = *prev(low.end());

            long long leftCost =
                median * (long long)low.size() - sumLow;

            long long rightCost =
                sumHigh - median * (long long)high.size();

            return leftCost + rightCost;
        };
        for (int i = 0; i < x; i++) {
            add(nums[i]);
        }
        cost[0] = getCost();
        for (int i = x; i < n; i++) {
            remove(nums[i - x]);
            add(nums[i]);

            cost[i - x + 1] = getCost();
        }
        const long long INF = 4e18;

        vector<vector<long long>> dp(
            k + 1,
            vector<long long>(n + 1, INF)
        );
        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }

        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= n; i++) {
                dp[j][i] = dp[j][i - 1];
                if (i >= x && dp[j - 1][i - x] != INF) {
                    dp[j][i] = min(
                        dp[j][i],
                        dp[j - 1][i - x] + cost[i - x]
                    );
                }
            }
        }

        return dp[k][n];
    }
};