class Solution {
public:
     vector<vector<int>>directions = {{1, 0} , {-1 ,0} ,{0 ,1} , {0,-1}};

    bool dfs(vector<vector<int>>&cells , int i , int j , int r , int c){
       
      if(i <0 || i>=r  || j<0  || j>=c || cells[i][j] == 1) return false;

      if(i==r-1) return true;
      cells[i][j] =1 ; 
      for(vector<int>&dir : directions){
        int newi = i+ dir[0];
        int newj = j+ dir[1];
        if(dfs(cells , newi , newj , r , c)) return true;
      }
      return false ;
    }

    bool isway(vector<vector<int>>& cells , int day , int r , int c){
          vector<vector<int>>grid(r , vector<int>(c));
          //fill the water till day(mid)
          for(int i = 0 ; i<=day ; i++){
            int row = cells[i][0]-1;
            int col = cells[i][1]-1;
            grid[row][col] =1;
          }
          for(int j = 0 ; j<c ; j++){
            if(grid[0][j]==0 && dfs(grid ,0 , j, r , c )){
                return true;
            }
           
          }
           return false ;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        int n = cells.size();

        int  l = 0; int r = cells.size()-1;

        int lastday = 0  ;
        

        //bin search for that day . 
        while(l<=r){
            int mid  = l+(r-l) /2;

            if(isway(cells , mid, row , col)){
                 lastday = mid+1;
                l = mid+1 ;
                 }else
                 r= mid-1;
        }
        return lastday ; 
        
    }
};