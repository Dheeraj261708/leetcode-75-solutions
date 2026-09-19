class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        vector<int> stk;

        stk.push_back(0);
        visited[0] = true;
        int visitedCount = 1;

        while (!stk.empty()) {
            int current = stk.back();
            stk.pop_back();

            for (int key : rooms[current]) {
                if (!visited[key]) {
                    visited[key] = true;
                    visitedCount++;
                    stk.push_back(key);
                }
            }
        }

        return visitedCount == n;
    }
};