class Solution {
public:
int f(int k , int n , int idx , int buy , vector<int>&prices , vector<vector<vector<int>>>&dp){
        if(k==0 ) return 0 ; 
        if(idx==n) return 0;

        if(dp[idx][k][buy] != -1) return dp[idx][k][buy];
    if(buy){
        return dp[idx][k][buy]= max(-prices[idx] + f(k , n , idx+1 ,0 , prices,dp) , f(k , n , idx+1 , 1 , prices ,dp));
    }else {
        return dp[idx][k][buy]= max(prices[idx] + f(k-1 , n , idx+1 , 1 , prices,dp) , f(k , n , idx+1 , 0, prices ,dp));
    }

}
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1 , vector<vector<int>>(k+1 , vector<int>(3 ,-1)));
          return f(k , n , 0 , 1 , prices  ,dp);
    }
};