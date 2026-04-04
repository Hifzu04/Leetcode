class Solution {
public:
    void solve(vector<int>& candidates, vector<vector<int>>& result,
               vector<int> temp, int i, int t) {
        if (t < 0) {
            return;
        }
        if (t == 0) {
            result.push_back(temp);
            return;
        }

        // Do
        for (int idx = i; idx < candidates.size(); idx++) {
            if (idx > i && candidates[idx] == candidates[idx - 1]) {
                continue;
            }
            temp.push_back(candidates[idx]);                           // DO
            solve(candidates, result, temp, idx, t - candidates[idx]); // Explore
            temp.pop_back();                                           // undo
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());

        solve(candidates, result, temp, 0, target);

        return result;
    }
};