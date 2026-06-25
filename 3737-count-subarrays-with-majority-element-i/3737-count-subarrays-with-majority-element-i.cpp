class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {  
         int ans = 0 ;
         int n = nums.size();
        for (int i = 0; i < n; i++) {
            int cntm = 0;
            for (int j = i; j < n; j++) {
                if(nums[j] == target){
                    cntm++;
                }
                if(cntm > (j-i+1)/2){
                    ans++;
                }
            }
        }
        return ans;
    }
};