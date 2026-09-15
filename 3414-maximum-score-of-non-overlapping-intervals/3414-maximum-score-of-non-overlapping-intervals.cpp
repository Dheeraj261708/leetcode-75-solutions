class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({intervals[i][0], intervals[i][1], intervals[i][2], i});
        }

        sort(a.begin(), a.end());
        struct State {
            long long weight = 0;
            vector<int> indices;
        };

        vector<vector<State>> dp(n + 1, vector<State>(5));
        vector<int> next(n);

        for (int i = 0; i < n; i++) {
            int l = i + 1, r = n;

            while (l < r) {
                int mid = l + (r - l) / 2;

                if (a[mid][0] > a[i][1])
                    r = mid;
                else
                    l = mid + 1;
            }

            next[i] = l;
        }

        auto better = [](const State& x, const State& y) {
            if (x.weight != y.weight)
                return x.weight > y.weight;

            return x.indices < y.indices;
        };

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {

                State skip = dp[i + 1][k];

                State take = dp[next[i]][k - 1];

                take.weight += a[i][2];
                take.indices.push_back((int)a[i][3]);

                sort(take.indices.begin(), take.indices.end());

                dp[i][k] = better(take, skip) ? take : skip;
            }
        }

        return dp[0][4].indices;
    }
};