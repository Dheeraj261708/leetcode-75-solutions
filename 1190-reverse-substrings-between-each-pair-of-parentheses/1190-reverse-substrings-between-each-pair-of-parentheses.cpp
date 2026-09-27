class Solution {
public:
    string reverseParentheses(string s) {
        string st;
        for (char c : s) {
            if (c == ')') {
                string temp = "";
                while (!st.empty() && st.back() != '(') {
                    temp += st.back();
                    st.pop_back();
                }
                if (!st.empty()) st.pop_back();
                st += temp;
            } else {
                st.push_back(c);
            }
        }
        return st;
    }
};