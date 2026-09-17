class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> minLen(n, INT_MAX);
        
        int left = 0;
        int currentSum = 0;
        int result = INT_MAX;
        int currentMinLen = INT_MAX;
        
        for (int right = 0; right < n; ++right) {
            currentSum += arr[right];
            while (currentSum > target) {
                currentSum -= arr[left];
                left++;
            }

            if (currentSum == target) {
                int length = right - left + 1;
                if (left > 0 && minLen[left - 1] != INT_MAX) {
                    result = min(result, length + minLen[left - 1]);
                }
                
                currentMinLen = min(currentMinLen, length);
            }
            minLen[right] = currentMinLen;
        }
        
        return result == INT_MAX ? -1 : result;
    }
};