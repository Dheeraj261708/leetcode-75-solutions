class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int open_needed = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                open_needed++;
            } else {
                if (i + 1 < n && s[i + 1] == ')') {
                    i++; 
                } else {
                    insertions++; 
                }
                if (open_needed > 0) {
                    open_needed--;
                } else {
                    insertions++;
                }
            }
        }
        insertions += open_needed * 2;
        
        return insertions;
    }
};