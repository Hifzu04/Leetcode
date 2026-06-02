#include <vector>
#include <algorithm>
#include <limits>
using namespace std;

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int best = numeric_limits<int>::max();

        for (int i = 0; i < n; ++i) {
            int ls = landStartTime[i];
            int ld = landDuration[i];
            for (int j = 0; j < m; ++j) {
                int ws = waterStartTime[j];
                int wd = waterDuration[j];

                // Plan A: land → water
                int finishLand = ls + ld;
                int startWater = max(finishLand, ws);
                int finishA = startWater + wd;

                // Plan B: water → land
                int finishWater = ws + wd;
                int startLand = max(finishWater, ls);
                int finishB = startLand + ld;

                best = min(best, min(finishA, finishB));
            }
        }

        return best;
    }
};
