class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());
        int distanceValue = 0;
        
        for (int x : arr1) {
            auto it = upper_bound(arr2.begin(), arr2.end(), x);
            bool isValid = true;
            if (it != arr2.end() && abs(*it - x) <= d) {
                isValid = false;
            }
            if (isValid && it != arr2.begin()) {
                auto prev_it = prev(it);
                if (abs(*prev_it - x) <= d) {
                    isValid = false;
                }
            }
            
            if (isValid) {
                distanceValue++;
            }
        }
        return distanceValue;
    }
};