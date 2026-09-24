class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());

        vector<vector<string>> ans;
        string prefix = "";

        for (char ch : searchWord) {
            prefix += ch;

            int pos = lower_bound(products.begin(), products.end(), prefix) - products.begin();

            vector<string> suggestions;

            for (int i = pos; i < products.size() && suggestions.size() < 3; i++) {
                if (products[i].compare(0, prefix.size(), prefix) == 0) {
                    suggestions.push_back(products[i]);
                } else {
                    break;
                }
            }

            ans.push_back(suggestions);
        }

        return ans;
    }
};