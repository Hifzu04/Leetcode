class Solution {
public:
    int f(int idx, vector<int>& nums, vector<int>& memo) {
        if (idx == nums.size() - 1) {
            return 0;
        }
        if (memo[idx] != -1) {
            return memo[idx];
        }
        int ans = INT_MAX;
        for (int i = 1; i <= nums[idx]; i++) {
            if (i + idx < nums.size()) {
                int next = f(idx + i, nums, memo);
                if (next != INT_MAX)
                    ans = min(ans, next + 1);
            }
        }
        return memo[idx] = ans;
    }
    int jump(vector<int>& nums) {
        vector<int> memo(10001, -1);
        return f(0, nums, memo);
    }
};