class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> nonZero1, nonZero2;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (img1[i][j] == 1) nonZero1.push_back({i, j});
                if (img2[i][j] == 1) nonZero2.push_back({i, j});
            }
        }
        vector<vector<int>> shiftCounts(2 * n + 1, vector<int>(2 * n + 1, 0));
        int maxOverlap = 0;
        for (const auto& p1 : nonZero1) {
            for (const auto& p2 : nonZero2) {
                int dr = p2.first - p1.first + n; 
                int dc = p2.second - p1.second + n;  
                shiftCounts[dr][dc]++;
                maxOverlap = max(maxOverlap, shiftCounts[dr][dc]);
            }
        }
        return maxOverlap;
    }
};