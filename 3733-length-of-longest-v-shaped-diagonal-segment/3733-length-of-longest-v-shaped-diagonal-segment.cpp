class Solution {
public:
vector<vector<int>>directions{{1,1} , {1,-1} ,{-1,-1} ,{-1 ,1}};
int n , m;
int t[501][501][4][2];

int f(int i , int j , int d  ,bool canTurn , int val , vector<vector<int>>&grid ){
    int i_ = i+directions[d][0];
    int j_ = j+ directions[d][1];

    if(i_<0 || i_>=m || j_<0 || j_>=n || grid[i_][j_] != val){
        return 0;
    }   
    if(t[i_][j_][d][canTurn] != -1){
          return t[i_][j_][d][canTurn];
    }
       int res = 0 ; 
    int move = 1+ f(i_ , j_ ,d , canTurn ,val==2 ? 0: 2, grid);
    res = max(res,move);
    if(canTurn){
        int turn = max(move ,1+ f( i_ , j_ ,(d+1)%4 , false ,val==2 ? 0: 2, grid));
        res = max(res , turn );
    }
    return t[i_][j_][d][canTurn]=  res ;
  

}
    int lenOfVDiagonal(vector<vector<int>>& grid) {
         m = grid.size();
        n= grid[0].size();
        memset(t , -1 , sizeof(t));
        int maxm = 0 ;
        int res = 0 ; 
        for(int i =0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j]==1){
                     for(int  d = 0 ; d<4 ; d++){
                        res = max(res , 1+f(i , j , d , true , 2 , grid  ) );
                     }

                }
                
               
            }
        }
        return res;
    }
};