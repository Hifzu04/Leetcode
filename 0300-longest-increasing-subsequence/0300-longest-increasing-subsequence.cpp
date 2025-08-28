class Solution {
public:
  int f(int prev , int curr , vector<int>&nums , int n , vector<vector<int>>&dp ){

    if(curr==n){
        return 0;
    }
       int take = -1 ;
    if(dp[curr][prev+1] != -1) return dp[curr][prev+1];
   
    
    if(prev== -1 || nums[curr]>nums[prev]){
         take = 1+f(curr ,curr+1 , nums , n  ,dp);
    }
    int nottake = f(prev , curr+1 , nums , n ,dp);

    return dp[curr][prev+1] = max(take ,nottake);
  }
    int lengthOfLIS(vector<int>& nums) {

        vector<vector<int>>dp(nums.size(), vector<int>(nums.size()+1 , -1));
        
        return f(-1 , 0 , nums  , nums.size() ,dp);
    }
};