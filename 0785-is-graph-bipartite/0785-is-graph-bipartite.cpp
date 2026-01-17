class Solution {
public:
    bool checkBipartiteDFS(vector<vector<int>>& adj, vector<int>& colorvec,
                           int currnode, int currcol) {

        colorvec[currnode] = currcol;

        for (auto& v : adj[currnode]) {
            if (colorvec[v] == colorvec[currnode]) {
                return false;
            }
            if (colorvec[v] == -1) {
                colorvec[v] = 1 - currcol; // flip the color
                if (checkBipartiteDFS(adj, colorvec, v, colorvec[v]) == false) {
                    return false;
                }
            }
        }
        return true;
    }

    bool CheckBiprtiteBFS(vector<vector<int>>& adj, vector<int>& colorvec,
                          int u, int currcol) {
        queue<int> q;
        q.push(u);
        colorvec[u] = currcol;

        while (!q.empty()) {
            int U = q.front();
            q.pop();

            for (auto& v : adj[U]) {
                if (colorvec[v] == colorvec[U])
                    return false;

                if (colorvec[v] == -1) {
                    colorvec[v] = 1 - colorvec[U];
                    q.push(v);
                }
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& adj) {
        int V = adj.size();
        // works as isvisited also
        vector<int> colorvec(V, -1);

        // 1 for red color , 0 for black color

        for (int i = 0; i < V; i++) {
            if (colorvec[i] == -1) {
                //  if(checkBipartiteDFS(adj , colorvec , i , 1)== false ){
                //     return false ;
                //  }

                if (CheckBiprtiteBFS(adj, colorvec, i, 1) == false) {
                    return false;
                }
            }
        }
        return true;
    }
};