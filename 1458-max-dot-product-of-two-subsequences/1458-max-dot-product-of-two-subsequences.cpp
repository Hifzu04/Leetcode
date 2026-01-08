//LCS concept
//We have 4 options take only i&j , take i and move for j, take j and move for i , move for i and j.
 // 4^(i+j);
class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2 , int i , int j ,vector<vector<int>>&dp ){
        if(i==nums1.size() || j==nums2.size()){
            return -1e9;
        }
        if(dp[i][j] != -1e9) return dp[i][j];
       int takeOnlyi_j = (nums1[i]*nums2[j]);
     //  int takeNone = solve(nums1 , nums2 , i+1 , j+1 ,dp);
       int takei_J_and_take_further = (nums1[i]*nums2[j]) + solve(nums1 , nums2 , i+1 , j+1 ,dp);
       int take_i = solve(nums1 , nums2 , i , j+1 ,dp);
       int take_j = solve(nums1, nums2 , i+1 , j ,dp);

       return dp[i][j] = max({takeOnlyi_j, takei_J_and_take_further, take_i, take_j });

    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
      
         vector<vector<int>>dp(501 , vector<int>(501 , -1e9));
        return solve(nums1 , nums2 , 0 , 0 ,dp);
    }
};