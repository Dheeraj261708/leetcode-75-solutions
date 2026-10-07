class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> visited;
        queue<string> q;
        q.push(s);
        visited.insert(s);
        bool found = false;
        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            if (isValid(curr)) {
                ans.push_back(curr);
                found = true;
            }
            if (found) continue;
            for (int i = 0; i < curr.size(); i++) {
                if (curr[i] != '(' && curr[i] != ')')
                    continue;

                string next = curr.substr(0, i) + curr.substr(i + 1);

                if (visited.find(next) == visited.end()) {
                    visited.insert(next);
                    q.push(next);
                }
            }
        }
        return ans;
    }
private:
    bool isValid(string s) {
        int balance = 0;
        for (char c : s) {
            if (c == '(') {
                balance++;
            }
            else if (c == ')') {
                balance--;
                if (balance < 0)
                    return false;
            }
        }
        return balance == 0;
    }
};