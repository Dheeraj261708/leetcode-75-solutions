class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        queue<int> radiant;
        queue<int> dire;
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R') {
                radiant.push(i);
            } else {
                dire.push(i);
            }
        }
        while (!radiant.empty() && !dire.empty()) {
            int rIdx = radiant.front();
            radiant.pop();
            int dIdx = dire.front();
            dire.pop();
            if (rIdx < dIdx) {
                radiant.push(rIdx + n);
            } else {
                dire.push(dIdx + n);
            }
        }
        
        return radiant.empty() ? "Dire" : "Radiant";
    }
};