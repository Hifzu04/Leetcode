class Solution {
public:

    typedef long long ll;
    ll MOD = 1e9 + 7;
    //fast expo template
     ll power(ll base , ll expo){
          if(expo == 0){
            return 1 ;
          }

          ll half = power(base , expo/2);
          ll result = half * half %MOD;
          if (expo & 1){
            result = (result * base )% MOD;
          }
          return result;
     }
    int getMaxDepth( unordered_map<int, vector<int>>& adj , int node , int parent){
        int depth = 0 ;
        for(int neighbour : adj[node]){
            if (neighbour == parent) continue;
           depth = max(depth , getMaxDepth(adj , neighbour , node)+1);
        }
        return depth;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto & x: edges){
            int u = x[0];
            int v = x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int MaxDepth = getMaxDepth(adj, 1 , -1);
         return power(2 , MaxDepth-1);

    }
};