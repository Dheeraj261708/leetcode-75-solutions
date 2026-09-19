class Solution {
private:
    void dfs(int node, int parent, const std::vector<std::vector<std::pair<int, int>>>& adj, int& changes) {
        for (const auto& [neighbor, sign] : adj[node]) {
            if (neighbor != parent) {

                changes += sign;
                dfs(neighbor, node, adj, changes);
            }
        }
    }

public:
    int minReorder(int n, std::vector<std::vector<int>>& connections) {
        std::vector<std::vector<std::pair<int, int>>> adj(n);
        
        for (const auto& conn : connections) {
            adj[conn[0]].push_back({conn[1], 1}); 
            adj[conn[1]].push_back({conn[0], 0});
        }

        int changes = 0;
        dfs(0, -1, adj, changes);
        
        return changes;
    }
};