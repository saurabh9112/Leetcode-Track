// Last updated: 8/11/2025, 12:05:21 AM
class Solution {
public:
    void dfs(int node, vector<int> &visited,unordered_map<int, vector<pair<int,int>>> &adj,int &cnt) {
        visited[node] = 1;
        for (auto &[neighbour, needsReverse] : adj[node]) {
            if (!visited[neighbour]) {
                cnt += needsReverse;
                dfs(neighbour, visited, adj, cnt);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        unordered_map<int, vector<pair<int,int>>> adj;

        for (auto &edge : connections) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back({v, 1}); 
            adj[v].push_back({u, 0});
        }
        vector<int> visited(n, 0);
        int cnt = 0;
        dfs(0, visited, adj, cnt);
        return cnt;
    }
};
