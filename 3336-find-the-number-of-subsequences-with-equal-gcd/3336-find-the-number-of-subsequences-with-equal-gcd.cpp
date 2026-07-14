class Solution {
public:
    int t[201][201][201];
    int mod = 1e9+7;
    int dp(vector<int>& nums, int i, int seq1, int seq2) {
        if (i == nums.size()) {
            if (seq1 != 0 && seq2 != 0 && seq1 == seq2) {
                return 1;
            }
            return 0;
        }
        if (t[i][seq1][seq2] != -1) {
            return t[i][seq1][seq2];
        }
        int skip = dp(nums, i + 1, seq1, seq2);
        int ans1 = dp(nums, i + 1, __gcd(seq1, nums[i]), seq2);
        int ans2 = dp(nums, i + 1, seq1, __gcd(seq2, nums[i]));

        return t[i][seq1][seq2]  = (0LL + skip + ans1 + ans2)%mod;
    }
    int subsequencePairCount(vector<int>& nums) {
         memset(t , -1 , sizeof(t));
         return dp(nums, 0, 0, 0); 
         }
};

// for each ele
// either i cna skip , or put it in sq1 or in seq2