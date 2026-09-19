class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations,
    vector<double>& values,
    vector<vector<string>>queries) {   
        unordered_map<string, vector<pair<string, double>>> graph;
        for (int i = 0; i < equations.size(); i++) {
            string a = equations[i][0];
            string b = equations[i][1];
            double value = values[i];

            graph[a].push_back({b, value});
            graph[b].push_back({a, 1.0 / value});
        }
        vector<double> ans;
        for (auto &query : queries) {
            string start = query[0];
            string end = query[1];

            if (graph.find(start) == graph.end() ||
                graph.find(end) == graph.end()) {
                ans.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;
            function<double(string, string, double)> dfs =
                [&](string current, string target, double product) -> double {
                    if (current == target)
                        return product;
                    visited.insert(current);
                    for (auto &[next, weight] : graph[current]) {
                        if (visited.count(next))
                            continue;

                        double result = dfs(next, target, product * weight);
                        if (result != -1.0)
                            return result;
                    }
                    return -1.0;
                };
            ans.push_back(dfs(start, end, 1.0));
        }
        return ans;
    }
};