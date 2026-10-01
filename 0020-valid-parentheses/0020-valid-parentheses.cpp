class Solution {
public:
    bool isValid(string s) {
        stack<char> test;

        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                test.push(ch);
            } else {
                if (test.empty()) {
                    return false;
                }

                if ((ch == ')' && test.top() != '(') ||
                    (ch == '}' && test.top() != '{') ||
                    (ch == ']' && test.top() != '[')) {
                    return false;
                }

                test.pop();
            }
        }

        return test.empty();
    }
};