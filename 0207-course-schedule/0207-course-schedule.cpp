// Directed graph
// if cyle exist  =>we cant complete all the courses
// check cycle => topoSort and if u get all the node => no cylce => return true;
//  For toposort(DAG) => BFS (Kahn's algo)
// kahn's algo =>create indegree => indegree 0 wale ko que me store karo => do
// bfs and reduce 1 from indegree[node v] 
//  [v, u] : v<----u  ie. prerequisites[i][0] <------  prerequisites[i][1]
class Solution {
public:
    bool bfs(int n, unordered_map<int, vector<int>>& adj,
        vector<int>& indegree) {
        queue<int> q;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                cnt++;
                indegree[i]--;
            }
        }

        while (!q.empty()) {
            int u = q.front();

            q.pop();
            for (auto& v : adj[u]) {
               
                 indegree[v]--;

                if ( indegree[v]==0) {
                    q.push(v);
                    cnt++;
                }
            }
        }
        return (cnt==n);
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        // inorder u---->v
        vector<int> inorder(n, 0);
        // adj list
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < prerequisites.size(); i++) {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            inorder[prerequisites[i][0]]++;
        }

        return bfs(n, adj, inorder);
    }
};