class Solution {
public:
    int dfs(  unordered_map<int, vector<int>>& adj, vector<bool>& visited , int u) {
        visited[u] = true;
        int count =1;
        for(int &v : adj[u]){
            if(!visited[v]){
               count += dfs(adj , visited  , v);
            }
        }
        
        return count ;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long remaining = n;
        long long  ans = 0;
        vector<bool> visited(n, false);
         unordered_map<int, vector<int>> adj;
        for (auto& vec : edges) {

            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                long long  currConn = dfs(adj, visited  , i);
                ans += (currConn * (remaining - currConn));
                remaining -= currConn;
            }
        }
        return ans;
    }
};