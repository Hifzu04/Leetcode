class Solution {
    int f(int i , vector<int>&prices , bool buy ,vector<vector<int>>&dp){
        if(i==prices.size()){
            return 0;
        }
        
        if(dp[i][buy] != -1) return dp[i][buy]  ;     
         if(buy){
            int today = -prices[i] + f(i+1 , prices , false ,dp);
            int notT = f(i+1 , prices , true ,dp);
            return dp[i][buy] = max(today,notT);
        }
        else {
            int today = prices[i] +f(i+1 , prices, true ,dp);
            int nott = f(i+1 , prices , false ,dp);
            return dp[i][buy] = max(today , nott);
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n , vector<int>(2 , -1));
        return f(0 , prices , true ,dp);
    }
};;