class Solution {
public:
    int numberOfSets(int n, int k) {
        long long MOD = 1e9 + 7;
        long long total_items = n + k - 1;
        long long choose_k = 2 * k;

        if (choose_k > total_items) return 0;
        vector<long long> dp(choose_k + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= total_items; ++i) {
            for (int j = min((long long)i, choose_k); j > 0; --j) {
                dp[j] = (dp[j] + dp[j - 1]) % MOD;
            }
        }

        return dp[choose_k];
        
    }
};