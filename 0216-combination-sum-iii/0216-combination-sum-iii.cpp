class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> current;
        function<void(int, int, int)> backtrack =
            [&](int start, int count, int sum) {
                if (count == k) {
                    if (sum == n) {
                        ans.push_back(current);
                    }
                    return;
                }
                for (int i = start; i <= 9; i++) {
                    if (sum + i > n)
                        break;

                    current.push_back(i);

                    backtrack(i + 1, count + 1, sum + i);

                    current.pop_back();
                }
            };

        backtrack(1, 0, 0);

        return ans;
    }
};