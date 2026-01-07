class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited,
             int n) {
        visited[u] = true;
        for (int & v : adj[u]) {
            if (!visited[v]) {
                dfs(adj, v, visited, n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        unordered_map<int, vector<int>> adj;
        vector<bool> visited(n, false);
        // adjacency list
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(adj, i, visited, n);
                cnt++;
            }
        }
        return cnt;
    }
};