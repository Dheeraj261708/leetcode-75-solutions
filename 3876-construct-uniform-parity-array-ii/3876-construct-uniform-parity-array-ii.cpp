class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minVal = nums1[0];
        bool hasOdd = false;

        for (int x : nums1) {
            minVal = std::min(minVal, x);
            if (x % 2 != 0) {
                hasOdd = true;
            }
        }
        if (!hasOdd) {
            return true;
        }
        return (minVal % 2 != 0);    
    }
};