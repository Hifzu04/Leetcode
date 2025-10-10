class Solution {
public:
    int f(int idx, vector<int>& energy, int k, vector<int>& dp) {
        if (idx >= energy.size()) return 0;
        if (dp[idx] != INT_MIN) return dp[idx];

       
        dp[idx] = energy[idx] + f(idx + k, energy, k, dp);
        return dp[idx];
    }

    int maximumEnergy(vector<int>& energy, int k) {
        int n = energy.size();
        vector<int> dp(n, INT_MIN);
        int ans = INT_MIN;

  
        for (int i = 0; i < n; i++) {
            ans = max(ans, f(i, energy, k, dp));
        }

        return ans;
    }
};
