class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b) {
            if (a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        int bigone0 = intervals[0][0];
        int bigone1 = intervals[0][1];
        int removecnt = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (bigone0 <= intervals[i][0] && bigone1 >= intervals[i][1]) {
                removecnt++;
            } else {
                bigone0 = intervals[i][0];
                bigone1 = intervals[i][1];
            }
        }
        return n - removecnt;
    }
};