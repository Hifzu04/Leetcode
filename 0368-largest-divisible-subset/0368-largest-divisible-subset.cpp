class Solution {
public:
    void f(int i, vector<int>& nums, vector<int>& curr, vector<int>& ans,
           int prev) {

        if (i >= nums.size()) {
            if (curr.size() > ans.size()) {
                ans = curr;
            }
            return ; 
        }

        if (prev == -1 || nums[i] % prev == 0) {
            curr.push_back(nums[i]);
            f(i + 1, nums, curr, ans, nums[i]);
            curr.pop_back();
        }

        /// not take
        f(i + 1, nums, curr, ans, prev);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n  = nums.size();
       // vector<int> curr;
        //vector<int> ans;
        //int prev = -1;
      //  f(0, nums, curr, ans, prev);

      
      vector<int>dp(n , 1 );
      vector<int>previdx(n , -1);
      int maxl = 1 ;
      int lastidx = 0 ;
      for(int i =1 ; i<n ; i++ ){
        for(int j = 0 ; j<i ; j++){
            if(nums[i]%nums[j]==0){
                if(dp[i]<1+dp[j]){
                dp[i] = dp[j]+1;
                previdx[i] = j; 
                }
            }

            if(dp[i] > maxl){
                maxl = dp[i];
                lastidx = i; 
            }
        }
      }

      vector<int>ans;
      while(lastidx != -1){
        ans.push_back(nums[lastidx]);
        lastidx = previdx[lastidx];
      }
      return ans; 
    }
};