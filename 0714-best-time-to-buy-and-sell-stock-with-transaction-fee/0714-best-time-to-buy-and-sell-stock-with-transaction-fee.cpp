class Solution {
public:
    int f(int i , int n , vector<int>&prices , int fee ,int buy , vector<vector<int>>&dp){
        if(i==n) return 0;
        if(dp[i][buy] != -1){
            return dp[i][buy];
        }
        
        if(buy){
            int take = -prices[i] +f(i+1 , n , prices , fee , 0 ,dp);
            int nott = f(i+1 , n , prices , fee , 1 ,dp);
            return  dp[i][buy]=max(take  , nott);
        }else {

            int take = (prices[i]-fee)  + f(i+1 , n , prices , fee , 1 ,dp);
            int nott = 0 + f(i+1 , n , prices , fee , 0 ,dp);
            return dp[i][buy]= max(take  , nott );
        }

    }
    int maxProfit(vector<int>& prices, int fee) {
       
        int n = prices.size();
         vector<vector<int>>dp(n+1 , vector<int>(2 , -1));

        return f(0 , n ,prices , fee  , 1 ,dp );
    }
};