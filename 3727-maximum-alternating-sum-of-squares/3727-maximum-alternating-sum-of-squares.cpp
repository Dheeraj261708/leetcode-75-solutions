class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> squared(n);
        for (int i = 0; i < n; ++i) {
            long long val = nums[i];
            squared[i] = val * val;
        }
        sort(squared.begin(), squared.end());
        long long maxScore = 0;
        for (int i = 0; i < n; ++i) {
            if (i < n / 2) {
                maxScore -= squared[i];
            } else {
                maxScore += squared[i];
            }
        }
        
        return maxScore;
    }
};