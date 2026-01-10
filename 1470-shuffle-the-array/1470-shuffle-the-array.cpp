class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int N) {
     //   int n = N*2;
        vector<int>ans;
        for(int i = 0 ; i< N; i++){
            ans.push_back(nums[i]);
            ans.push_back(nums[i+N]);
        }
        return ans;
    }
};