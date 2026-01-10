class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxm = 0 ;
        int n = nums.size();
        int cnt =0  ;
        for(int i = 0 ; i<n ; i++ ){
              if(nums[i]==0){
                cnt= 0 ; continue;
              }
              cnt++;
              maxm= max(maxm , cnt);

        }
        return maxm; 
    }
};