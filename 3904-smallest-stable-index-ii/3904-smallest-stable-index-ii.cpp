class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        std::vector<int> suffMin(n);
        suffMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suffMin[i] = std::min(nums[i], suffMin[i + 1]);
        }
        int prefMax = nums[0];
        for (int i = 0; i < n; ++i) {
            prefMax = std::max(prefMax, nums[i]);
            if (prefMax - suffMin[i] <= k) {
                return i;
            }
        }
        
        return -1;
        
    }
};