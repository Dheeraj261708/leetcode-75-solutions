class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
         int n = costs.size();
        priority_queue<int, vector<int>, greater<int>> left;
        priority_queue<int, vector<int>, greater<int>> right;
        int l = 0;
        int r = n - 1;
        while (l <= r && left.size() < candidates) {
            left.push(costs[l]);
            l++;
        }
        while (l <= r && right.size() < candidates) {
            right.push(costs[r]);
            r--;
        }
        long long ans = 0;
        while (k--) {
            if (right.empty() ||
                (!left.empty() && left.top() <= right.top())) {

                ans += left.top();
                left.pop();
                if (l <= r) {
                    left.push(costs[l]);
                    l++;
                }
            }
            else {
                ans += right.top();
                right.pop();
                if (l <= r) {
                    right.push(costs[r]);
                    r--;
                }
            }
        }

        return ans;
    }
};