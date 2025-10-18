class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int prev = INT_MIN;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            int smallest = nums[i] - k;

            if (smallest <= prev && prev < nums[i] + k) {
                prev++;
                ans++;
            } else if (smallest > prev) {
                prev = smallest;
                ans++;
            }
        }
        return ans;
    }
};

// prev int max
// sort
// smallest = num[i] - k ;
// if(smallest <= prev){
// prev++;

//}
// else if (smallest > prev && smallest <= nums[i]+k){
// nums[i] - k ;
// ascorbic acid

//
//