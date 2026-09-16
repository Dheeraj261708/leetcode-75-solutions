class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<std::string> stringStack;
        string currentString = "";
        int k = 0;
        
        for (char ch : s) {
            if (isdigit(ch)) {
                k = k * 10 + (ch - '0');
            } else if (ch == '[') {
                countStack.push(k);
                stringStack.push(currentString);
                currentString = "";
                k = 0;
            } else if (ch == ']') {
                string decodedString = stringStack.top();
                stringStack.pop();
                int currentK = countStack.top();
                countStack.pop();
                
                while (currentK > 0) {
                    decodedString += currentString;
                    currentK--;
                }
                currentString = decodedString;
            } else {
                currentString += ch;
            }
        }
        
        return currentString;
        
    }
};