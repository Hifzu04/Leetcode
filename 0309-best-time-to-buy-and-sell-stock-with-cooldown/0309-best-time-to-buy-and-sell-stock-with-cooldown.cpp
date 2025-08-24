class Solution {

     int  f(int idx ,int n ,vector<int>& prices ,int buy , int cap , vector<vector<int>>&dp ){
         if(idx>=n) return 0;
         
        

        if(dp[idx][buy] != -1) return dp[idx][buy];
        if(buy==1){
             int pick = (-prices[idx] + f(idx+1 , n , prices , 0 , cap ,dp));
             int notpick = (0 + f(idx+1 , n , prices , 1 , cap ,dp));
             return dp[idx][buy] = max(pick,notpick);
        }
        else {
            int pick = (prices[idx] + f(idx+2 , n , prices , 1 , cap-1 ,dp));
            int notpick = (f(idx+1 , n , prices , 0 , cap ,dp));
            return dp[idx][buy]= max(pick,notpick);
        }
        return 0;
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size()+1 , vector<int>(3 ,-1));
        return f(0 , prices.size() , prices , 1 ,2 , dp);
        
    }
};





