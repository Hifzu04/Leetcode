class Solution {
public:
    int f(vector<int>&values , int i , int j , vector<vector<int>>&dp){
        int ans = INT_MAX;
        if(j-i <= 1 ){
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        for(int k = i+1 ; k<j ; k++){
            int wt = values[i]*values[j]*values[k] + f(values , i , k ,dp ) + f(values , k , j ,dp);
            ans = min(ans , wt);
        }
        return  dp[i][j] = ans;
    }
    int minScoreTriangulation(vector<int>& values) {
             vector<vector<int>>dp(51 , vector<int>(51 , -1));
             return  f(values , 0 , values.size()-1 , dp); 
    }
};