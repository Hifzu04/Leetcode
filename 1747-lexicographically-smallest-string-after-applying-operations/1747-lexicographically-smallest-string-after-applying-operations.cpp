
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addToOdd(const string &s, int a) {
        string t = s;
        for (int i = 1; i < (int)t.size(); i += 2) {
            int d = (t[i] - '0' + a) % 10;
            t[i] = char('0' + d);
        }
        return t;
    }

    string rotateRight(const string &s, int b) {
        int n = s.size();
        b %= n;
        if (b == 0) return s;
        
        return s.substr(n - b) + s.substr(0, n - b);
    }

    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> seen;
        queue<string> q;
        string best = s;

        q.push(s);
        seen.insert(s);

        while (!q.empty()) {
            string cur = q.front(); q.pop();
            
            if (cur < best) best = cur;

            
            string op1 = addToOdd(cur, a);
            if (!seen.count(op1)) {
                seen.insert(op1);
                q.push(op1);
            }

           
            string op2 = rotateRight(cur, b);
            if (!seen.count(op2)) {
                seen.insert(op2);
                q.push(op2);
            }
        }

        return best;
    }
};
