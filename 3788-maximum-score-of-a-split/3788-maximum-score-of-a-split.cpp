class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        vector<long long>ps(nums.size());
        vector<long long > sm(nums.size());
    
        long long   minm = 1e10;
        ps[0] = nums[0];
        for(int i = 1 ; i< nums.size() ; i++){
            ps[i] = ps[i-1]+ nums[i];
        }
        for(int i = nums.size()-1 ; i>= 0 ; i--){
            minm = min(minm , (long long)nums[i]);
            sm[i] = minm;
        }

        long long ans = -1e10;

        for(int i = 0 ; i<nums.size()-1 ; i++){
            
            ans = max(ans , (ps[i]-sm[i+1]));
        }

        return ans;
    }
};