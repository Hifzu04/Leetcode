class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans = 1;
         int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] > nums[j - 1]) {
                    ans = max(ans, j - i + 1);
                } else {
                    break;
                }
            }
        }


          for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[j - 1]) {
                    ans = max(ans, j - i + 1);
                } else {
                    break;
                }
            }
        }

        return ans;
    }
};