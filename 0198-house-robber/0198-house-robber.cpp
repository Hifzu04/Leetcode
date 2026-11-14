class Solution {
public:
    int t[101];
    int f(vector<int>& nums, int i) {
        if (i >= nums.size()) {
            return 0;
        }
        if(t[i] != -1) return t[i];
        int take = nums[i] + f(nums, i + 2);
        int skip = f(nums, i + 1);
        return t[i] = max(take , skip);
    }
    int rob(vector<int>& nums) { 
        memset(t , -1  , sizeof(t));
        return f(nums, 0); 
        }
};