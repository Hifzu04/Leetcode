class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i= 0 ; i<nums.size() ; i++){
            if(nums[i] <0) nums[i] *=-1;
        }
        sort(nums.begin() , nums.end());
        long long  sub = 0 ; long long add = 0  ;
        for(int i =  0 ; i< n/2 ; i++) sub+=(nums[i]*nums[i]);
        for(int i =  n/2 ; i< n ; i++) add+=(nums[i]*nums[i]);
        return add-sub;

 }
};