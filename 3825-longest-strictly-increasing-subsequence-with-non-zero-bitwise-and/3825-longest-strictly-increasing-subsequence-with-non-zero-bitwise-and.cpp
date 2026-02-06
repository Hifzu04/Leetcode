class Solution {
   
public:
    int lengthOfLIS(vector<int>& arr) {

        int n = arr.size();
        vector<int> ans;
        ans.push_back(arr[0]);

        for (int i = 1; i < n; i++) {
            if (arr[i] > ans.back() ) {
                ans.push_back(arr[i]);
            } else {
                int low = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
                ans[low] = arr[i];
            }

        }
        return ans.size();
    }
    

    int longestSubsequence(vector<int>& nums) {

        int n = nums.size();
        int maxm = 0;
        for (int i = 0; i < 32; i++) {
            vector<int> v;

            for (int j = 0; j < n; j++) {
                if (nums[j] & (1 << i)) {
                    v.push_back(nums[j]);
                }
            }
           if (!v.empty()) {
            maxm = max(maxm, lengthOfLIS(v));
}
        }

        return maxm;
    }
};
