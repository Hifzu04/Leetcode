class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int ans =0 ;
        int n =nums.size();
          vector<int>left(n), right(n) ;
        int lmaxm = nums[0];
        int rmaxm = nums[n-1];
        for(int i =0 ; i<n  ; i++) {
           lmaxm = max(lmaxm , nums[i]);
           left[i] = lmaxm;
        }
        for(int i = n-1 ; i>=0 ; i--){
            rmaxm = max(rmaxm , nums[i]);
            right[i] = rmaxm;
        }

        for(int i = 0 ; i< n ; i++){
            if(nums[i]<left[i] && nums[i]<right[i]){
                ans++;
            }
        }
        return ans;
      
    }
};