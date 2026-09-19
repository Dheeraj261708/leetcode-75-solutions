class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, n), last(26, -1);
        
        for (int i = 0; i < n; ++i) {
            int ch = s[i] - 'a';
            first[ch] = min(first[ch], i);
            last[ch] = max(last[ch], i);
        }

        vector<pair<int, int>> valid_intervals;

        for (int i = 0; i < 26; ++i) {
            if (first[i] == n) continue;

            int left = first[i];
            int right = last[i];
            bool valid = true;

            for (int j = left; j <= right; ++j) {
                int ch = s[j] - 'a';
                if (first[ch] < left) {
                    valid = false;
                    break;
                }
                right = max(right, last[ch]);
            }

            if (valid) {
                valid_intervals.push_back({right, left});
            }
        }
        sort(valid_intervals.begin(), valid_intervals.end());

        vector<string> result;
        int prev_end = -1;

        for (const auto& [right, left] : valid_intervals) {
            if (left > prev_end) {
                result.push_back(s.substr(left, right - left + 1));
                prev_end = right;
            }
        }
        return result;
    }
};