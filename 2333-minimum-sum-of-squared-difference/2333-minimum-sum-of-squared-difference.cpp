class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long totalOps = k1 + k2;
        vector<int> diff(n);
        long long initialSum = 0;
        int maxDiff = 0;
        
        for (int i = 0; i < n; ++i) {
            diff[i] = abs(nums1[i] - nums2[i]);
            initialSum += 1LL * diff[i] * diff[i];
            maxDiff = max(maxDiff, diff[i]);
        }
        vector<long long> count(maxDiff + 1, 0);
        for (int d : diff) {
            count[d]++;
        }
        for (int d = maxDiff; d > 0 && totalOps > 0; --d) {
            if (count[d] == 0) continue;
            
            long long opsToReduce = min(totalOps, count[d]);
            
            totalOps -= opsToReduce;
            count[d] -= opsToReduce;
            count[d - 1] += opsToReduce;
        }
        long long minSquareDiffSum = 0;
        for (int d = 0; d <= maxDiff; ++d) {
            if (count[d] > 0) {
                minSquareDiffSum += count[d] * 1LL * d * d;
            }
        }
        
        return minSquareDiffSum;
    }
};