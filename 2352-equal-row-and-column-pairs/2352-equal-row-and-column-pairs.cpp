class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        std::map<std::vector<int>, int> rowCounts;
        for (int i = 0; i < n; ++i) {
            rowCounts[grid[i]]++;
        }
        
        int pairs = 0;
        for (int j = 0; j < n; ++j) {
            std::vector<int> col(n);
            for (int i = 0; i < n; ++i) {
                col[i] = grid[i][j];
            }
            if (rowCounts.find(col) != rowCounts.end()) {
                pairs += rowCounts[col];
            }
        }
        
        return pairs;
        
    }
};