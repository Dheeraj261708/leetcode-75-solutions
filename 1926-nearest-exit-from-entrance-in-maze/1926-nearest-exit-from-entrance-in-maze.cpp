class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int steps = 0;
        int directions[4][2] = {{1, 0},{-1, 0},{0, 1},{0, -1}};
        while (!q.empty()) {
            int size = q.size();
            steps++;
            while (size--) {
                auto [r, c] = q.front();
                q.pop();
                for (auto &dir : directions) {
                    int nr = r + dir[0];
                    int nc = c + dir[1];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n &&maze[nr][nc] == '.') {
                        if (nr == 0 || nr == m - 1 ||nc == 0 || nc == n - 1) {
                            return steps;
                        }
                        maze[nr][nc] = '+';
                        q.push({nr, nc});
                    }
                }
            }
        }
        return -1;
    }
};