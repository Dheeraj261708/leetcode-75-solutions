class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.length();
        int count = 0;
        int i = 0;
        auto isPalindrome = [&](int l, int r) {
            while (l < r) {
                if (s[l++] != s[r--]) return false;
            }
            return true;
        };
        while (i < n) {
            if (i + k <= n && isPalindrome(i, i + k - 1)) {
                count++;
                i += k;
            } 
            else if (i + k + 1 <= n && isPalindrome(i, i + k)) {
                count++;
                i += k + 1; 
            } 
            else {
                i++;
            }
        }
        return count;
    }
};