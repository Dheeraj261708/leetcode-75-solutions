class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0); 

        for (char c : s) {
            if (c == '(') {
                st.push(0);
            } else {
                int innerScore = st.top();
                st.pop();
                int currentScore = max(2 * innerScore, 1);
                st.top() += currentScore;
            }
        }

        return st.top();
    }
};