class Solution {
public:
    int n ;
    int m; 

    int memo[501][501][3];
    int f(vector<vector<int>>& coins , int i , int j , int limit){

        if(i == m-1 && j == n-1){
            if(coins[i][j] < 0 && limit >0 ){
                return 0;

            }
            return coins[i][j];
        } 

        if(i >= m  || j >=n){
            return INT_MIN;
        }

        if (memo[i][j][limit] != -1e9) {
            return memo[i][j][limit];
        }

        //take 
        int take = coins[i][j] +  max( f(coins , i+1 , j, limit) , f(coins , i , j+1 , limit));

        //skip
        int skip = INT_MIN;
        if(coins[i][j] <  0 && limit >0) {
           int skipdown =  f(coins  , i+1 , j , limit-1) ;
            int skipRight =   f(coins , i , j+1 , limit-1);

            skip = max(skipdown ,skipRight);
        }


        return memo[i][j][limit] = max(take ,skip);





    }
    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = 0; k < 3; k++) {
                    memo[i][j][k] = -1e9;
                }
            }
        }
        return f(coins , 0 , 0 , 2);
    }
};