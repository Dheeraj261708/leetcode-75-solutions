class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int startX = -1, startY = -1;
        vector<pair<int, int>> litter;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (classroom[i][j] == 'S') {
                    startX = i;
                    startY = j;
                } else if (classroom[i][j] == 'L') {
                    litter.push_back({i, j});
                }
            }
        }
        
        int numLitter = litter.size();
        int targetMask = (1 << numLitter) - 1;
        
        // Map litter positions to their bit index
        vector<vector<int>> litterIdx(m, vector<int>(n, -1));
        for (int i = 0; i < numLitter; ++i) {
            litterIdx[litter[i].first][litter[i].second] = i;
        }
        int startMask = 0;
        if (litterIdx[startX][startY] != -1) {
            startMask |= (1 << litterIdx[startX][startY]);
        }
        vector<vector<vector<vector<bool>>>> visited(
            m, vector<vector<vector<bool>>>(
                n, vector<vector<bool>>(
                    energy + 1, vector<bool>(1 << numLitter, false))));
        queue<tuple<int, int, int, int>> q;
        q.push({startX, startY, energy, startMask});
        visited[startX][startY][energy][startMask] = true;
        
        int steps = 0;
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c, remEnergy, mask] = q.front();
                q.pop();
                
                if (mask == targetMask) {
                    return steps;
                }
                
                if (remEnergy == 0) continue;
                
                for (auto& d : dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];
                    
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && classroom[nr][nc] != 'X') {
                        int nextEnergy = (classroom[nr][nc] == 'R') ? energy : remEnergy - 1;
                        int nextMask = mask;
                        
                        if (classroom[nr][nc] == 'L') {
                            nextMask |= (1 << litterIdx[nr][nc]);
                        }
                        
                        if (!visited[nr][nc][nextEnergy][nextMask]) {
                            visited[nr][nc][nextEnergy][nextMask] = true;
                            q.push({nr, nc, nextEnergy, nextMask});
                        }
                    }
                }
            }
            steps++;
        }
        
        return -1;
        
    }
};