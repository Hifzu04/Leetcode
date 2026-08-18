class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
       int n = nums.size();
        
       
       
        vector<int> cnt(51, 0);
        
        for (int i = 0; i <= n - k; ++i) {
            // Avoid counting the same value twice in one subarray.
            bool seen[51] = {};
            
            for (int j = i; j < i + k; ++j) {
                if (!seen[nums[j]]) {
                    seen[nums[j]] = true;
                    cnt[nums[j]]++;
                }
            }
        }
        
        int ans = -1;
        for (int x = 0; x <= 50; ++x) {
            if (cnt[x] == 1) {
                ans = x;
            }
        }
        
        return ans;

    }
};