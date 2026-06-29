class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        sort(occupiedIntervals.begin(), occupiedIntervals.end());

        vector<vector<int>> merged;
        merged.push_back(occupiedIntervals[0]);

        for (int i = 1; i < occupiedIntervals.size(); i++) {
            if (occupiedIntervals[i][0] <= merged.back()[1] + 1) {
                merged.back()[1] = max(merged.back()[1], occupiedIntervals[i][1]);
            } else {
                merged.push_back(occupiedIntervals[i]);
            }
        }

        vector<vector<int>> ans;

        for (auto &x : merged) {
            int s = x[0], e = x[1];

            if (s < freeStart) {
                ans.push_back({s, min(e, freeStart - 1)});
            }

            if (e > freeEnd) {
                ans.push_back({max(s, freeEnd + 1), e});
            }
        }

        return ans;
    }
};