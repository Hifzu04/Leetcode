class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        if (2 * k > n) return false;

        for (int i = 0; i + 2*k <= n; i++) {
            bool f1 = false;
            bool f2 = false;

            
            int curridx = i;
            int end1 = i + k - 1; 
            int currcnt = 0;
            while (curridx < end1) {
                if (nums[curridx] >= nums[curridx + 1]) {
                    currcnt = 0;
                    break;
                }
                currcnt++;
                curridx++;
            }
            if (currcnt == k - 1) f1 = true;

            
            currcnt = 0;
            int start2 = i + k;
            for (int j = start2; j < start2 + k - 1; j++) {
                if (nums[j] >= nums[j + 1]) { 
                    currcnt = 0;
                    break;
                }
                currcnt++;
            }
            if (currcnt == k - 1) f2 = true;

            if (f1 && f2) return true;
        }

        return false;
    }
};
