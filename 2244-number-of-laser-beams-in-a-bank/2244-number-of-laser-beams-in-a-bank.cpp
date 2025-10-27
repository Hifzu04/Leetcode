#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        long long prevCount = 0;   
        long long beams = 0;
        for (const string &row : bank) {
            long long cnt = 0;
            for (char c : row) if (c == '1') ++cnt;
            if (cnt > 0) {
                if (prevCount > 0) beams += prevCount * cnt;
                prevCount = cnt;
            }
        }
        return (int)beams;
    }
};
