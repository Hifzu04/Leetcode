class Solution {
     int mod = 1e9+7;
public:
    int f(vector<vector<int>>&grid , int i , int j , int dir , int n , int m , vector<vector<vector<int>>>&dp){
        if (i==n-1 && j==m-1) return 1;
        if(i>=n || j>=m ) return 0;
        int ways = 0 ;

        if(dp[i][j][dir] != -1) return dp[i][j][dir];
        if(grid[i][j]==1){
            if(dir== 0){
                ways = f(grid , i , j+1 ,1, n ,m ,dp );
                
            }else {
                ways = f(grid , i+1 , j ,0, n , m ,dp );
               

            }
        }
        else {
            ways += f(grid , i+1 , j ,0, n , m  ,dp);
            ways += f(grid , i , j+1 , 1 , n , m,dp);
        }
        return dp[i][j][dir] = (int) ways%mod ;
    }
     
    int uniquePaths(vector<vector<int>>& grid) {
        //rows = 0 , col = 1 ; dir
        int n = grid.size();
        int m = grid[0].size();
       std::vector<std::vector<std::vector<int>>> dp(n+1, std::vector<std::vector<int>>(m+1, std::vector<int>(2, -1)));
        return f(grid , 0, 0, 0 , n , m , dp);
    }
};