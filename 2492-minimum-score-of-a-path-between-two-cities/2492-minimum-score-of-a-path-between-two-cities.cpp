class Solution {
public:
    void dfs(unordered_map<int, vector<pair<int,int>>>&adj , int&  ans , int u ,  vector<bool>& visited  ){

        visited[u] = true;
        for(auto & vec : adj[u]){
            int v = vec.first;
            int dist = vec.second;
            ans = min(ans , dist);
            if(!visited[v]){
                dfs(adj , ans , v , visited);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int ,vector<pair<int,int>>> adj;

        for(auto & vec : roads){
            int u = vec[0];
            int v = vec[1];
            int dist = vec[2];
            adj[u].push_back({v , dist});
            adj[v].push_back({u, dist});
        }

        int ans = INT_MAX;
        vector<bool>visited(n , false );
         
         dfs(adj , ans , 1 , visited);

         return ans;

    }
};


//Simple dfs or bfs (O(E+V))