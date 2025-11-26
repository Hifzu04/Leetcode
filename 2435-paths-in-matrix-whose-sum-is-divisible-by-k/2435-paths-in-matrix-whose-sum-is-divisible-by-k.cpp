class Solution {
    
public:
      int MOD = 1e9+7;
     int f(vector<vector<int>>&grid , int r , int c , int currsum ,int m , int n , int  k,  vector<vector<vector<int>>>&dp){
          if (r>=m || c>=n) return 0;
         if(r == m-1 && c == n-1){
            if((currsum+grid[r][c]) % k  ==0 ){
                return 1;
            }
            return 0;
         }
         if(dp[r][c][currsum] != -1 ) return dp[r][c][currsum];
        int right = f(grid , r , c+1 , (currsum+grid[r][c])%k , m , n , k, dp);
         int down = f(grid , r+1 , c , (currsum+grid[r][c])%k , m ,n , k ,dp);
         return dp[r][c][currsum] =  (right+down)%MOD;
     }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int currsum =0; 
        int m = grid.size() ; 
        int n = grid[0].size();
        vector<vector<vector<int>>>dp(m+1 , vector<vector<int>>(n+1 , vector<int>(51 , -1)));
        return f(grid , 0 , 0 , currsum , m , n , k  , dp);
    }
};