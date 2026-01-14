class Solution {
public:
    long long getMinV(long long X, int mask) {
       
        long long current = 0;
        for (int b = 30; b >= 0; b--) {
            if (mask & (1 << b)) {
                current |= (1 << b);
            } else {

                if ((current | ((1LL << b) - 1)) < X) {
                    current |= (1 << b);
                }
            }
        }
        return current;
    }
    int maximumAND(vector<int>& nums, int k, int m) {
        int maxi = 0;
        int currMask = 0;

        int n = nums.size();
        for (int j = 30; j >= 0; j--) {

            vector<int> cost;

            for (int i : nums) {
                int target = currMask | (1 << j);

                long long val = getMinV(i, target);

                cost.push_back(val - i);
            }

            sort(cost.begin(), cost.end());

            long long int mini = 0;
            for (int l = 0; l < m; l++) {
                mini += cost[l];
            }
            // cout<<mini<<" "<<j<<endl;
            if (mini <= k * 1LL) {

                currMask = currMask | (1 << j);
            }
        }

        return currMask;
    }
};