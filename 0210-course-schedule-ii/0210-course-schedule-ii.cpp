class Solution {
public:
   vector<int>toposort(unordered_map<int , vector<int>>&adj , int n , vector<int>& indegree){
        int  visitedNode =  0 ;
        queue<int>q;
        
        vector<int>ans;

        for(int i = 0 ; i< n  ; i++){
            if(indegree[i]==0){
                q.push(i);
                visitedNode++;
                ans.push_back(i);
            }
        }

        while(q.size()>0){
            int u = q.front();
            q.pop();

            for(auto& v  : adj[u]){
                indegree[v]--;

                if(indegree[v]==0){
                    q.push(v);
                    ans.push_back(v);
                    visitedNode++;
                }
            }

        }
       if(visitedNode== n) return ans;
        return {};
   }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        //Topological sort => ON DAG using BFS
        unordered_map<int , vector<int>>adj;
        vector<int>indegree(numCourses);

        for(auto& vec : prerequisites){
            int u = vec[1];
            int v = vec[0];

            adj[u].push_back(v);
            indegree[v]++;

           
        }

         return toposort(adj ,numCourses , indegree  );

    }
};