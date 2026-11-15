class Solution {
public:
    vector<vector<int>>direction = {{0,1} , {0, -1} , {1, 0} , {-1 , 0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>>q; 
        int countfresh = 0;
        for(int i = 0 ; i< n ; i++){
            for(int j = 0 ; j<m ; j++){

                if(grid[i][j] == 2){
                    q.push({i, j});     //init que where orange is rotton
                }
                if(grid[i][j] == 1) {
                    countfresh++;
                }
            }
        }
       int time = 0 ;
        while(!q.empty() && countfresh != 0 ){
            int currsize = q.size();
            while(currsize--){    
                auto pos = q.front();
                q.pop();
                int x= pos.first; 
                int y = pos.second;
                //visit neighbour if possilbe
                for(auto dir : direction){
                   int  new_x = x + dir[0];
                   int new_y = y + dir[1];
                    if(new_x < n && new_y < m && new_x >= 0 && new_y >= 0 && grid[new_x][new_y] == 1){
                        grid[new_x][new_y] = 2;  //marked rotten
                        q.push({new_x , new_y});
                        countfresh--;
                    }
                }    
            }
              time++;
        }

        if(countfresh == 0) return time  ; 
        return -1;
    }
};