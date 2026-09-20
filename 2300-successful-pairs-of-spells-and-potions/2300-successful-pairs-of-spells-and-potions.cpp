class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
         sort(potions.begin(), potions.end());

        vector<int> ans;

        for (long long spell : spells) {
            long long need = (success + spell - 1) / spell;
            int index = lower_bound(potions.begin(), potions.end(), need)
                        - potions.begin();

            ans.push_back(potions.size() - index);
        }

        return ans;
    }
};