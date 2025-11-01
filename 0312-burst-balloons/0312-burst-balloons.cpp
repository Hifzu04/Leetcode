class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n , vector<int>(n , -1));
        //see gap strategy for outer two loops
        for(int g = 0 ; g<n ; g++){
            for(int i =0, j= g ; j<n ; i++ , j++ ){
                int minm = INT_MIN;
                for(int k = i ; k<=j ; k++){
                    int left =  k==i ? 0: dp[i][k-1];
                    int right = k==j ? 0 : dp[k+1][j];
                    int val = (i >0 ? nums[i-1] : 1) * nums[k] * (j < n-1 ? nums[j+1] : 1);
                    int tot = left + right + val;
                    if(tot > minm){
                        minm = tot;
                    }
                }
                dp[i][j] = minm;
            }
        }
        return dp[0][n-1];
    }
};