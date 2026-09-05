class Solution {
private:
    inline bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
public:
    int maxVowels(string s, int k) {
        int currentVowels = 0;
        for (int i = 0; i < k; ++i) {
            if (isVowel(s[i])) {
                currentVowels++;
            }
        }
        int maxVowelsCount = currentVowels;
        if (maxVowelsCount == k) return k;
        for (int i = k; i < s.length(); ++i) {
            if (isVowel(s[i])) currentVowels++;    
            if (isVowel(s[i - k])) currentVowels--;  
            maxVowelsCount = max(maxVowelsCount, currentVowels);
            if (maxVowelsCount == k) return k;
        }
        
        return maxVowelsCount;
        
    }
};