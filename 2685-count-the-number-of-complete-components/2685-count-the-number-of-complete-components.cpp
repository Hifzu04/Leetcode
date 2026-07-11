class Solution {
public:
//IT can be solved with 3 approaches , solve it with other two
    void dfs(int i, unordered_map<int, vector<int>>& adj, int& v, int& e,
             vector<bool>& visited) {
        visited[i] = true;
        v ++;
        e += adj[i].size();

        for (int& neighbour : adj[i]) {
            if (!visited[neighbour]) {
                dfs(neighbour, adj, v, e, visited);
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, false);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]==true) {
                continue;
            }
            int v = 0;
            int e = 0;
            dfs(i, adj, v, e, visited);
            if (v * (v - 1) == e) {
                ans++;
            }
        }
        return ans;
    }
};