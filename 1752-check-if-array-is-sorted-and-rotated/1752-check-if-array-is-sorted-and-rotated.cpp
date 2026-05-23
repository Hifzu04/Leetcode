class Solution {
public:
    bool check(vector<int>& nums) {
        int k = 0;
        int n = nums.size();
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                k = i;
                break;
            }
        }

        if (k == n) {
            return true;
        }
        if (k != 0) {
            for (int i = k; i < n; i++) {
                if (nums[i] > nums[0])
                    return false;
                if (i != n - 1) {
                    if (nums[i] > nums[i + 1])
                        return false;
                }
            }
        }

        return true;
    }
};