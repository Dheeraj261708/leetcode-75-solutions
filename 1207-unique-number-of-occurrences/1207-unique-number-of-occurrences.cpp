class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> counts;
        for (int num : arr) {
            counts[num]++;
        }
        unordered_set<int> occurrences;
        for (auto& [num, count] : counts) {
            if (!occurrences.insert(count).second) {
                return false; 
            }
        }
        return true;
    }
};