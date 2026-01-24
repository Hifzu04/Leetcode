class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
        int maxm = INT_MIN;
        for(int i =0  ; i< n/2 ; i++){
            maxm = max(maxm , nums[i]+nums[n-i-1]);
        }
        return maxm;
    }
};