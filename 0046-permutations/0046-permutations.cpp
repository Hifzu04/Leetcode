class Solution {
public:
    vector<int> temp;
    unordered_set<int> vis;
    int n;
    void f(vector<vector<int>>& ans, vector<int>& nums) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (vis.find(nums[i]) == vis.end()) {
                temp.push_back(nums[i]);
                vis.insert(nums[i]);

                f(ans, nums);

                temp.pop_back();
                vis.erase(nums[i]);
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        n = nums.size();

        f(ans, nums);
        return ans;
    }
};