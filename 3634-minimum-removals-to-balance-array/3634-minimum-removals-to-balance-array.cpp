class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin() , nums.end());
          int minm = INT_MAX;
        for(int i = 0 ; i< n ; i++){
             long long target =(long long) nums[i] *k ;
             
             auto it  = upper_bound(nums.begin()+i  , nums.end() , target);
             int to_remove = n -  (it- nums.begin() - i );
             minm = min(minm , to_remove);

        }
        return minm;
    }
};