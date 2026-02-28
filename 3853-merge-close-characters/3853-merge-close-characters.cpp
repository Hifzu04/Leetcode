class Solution {
public:
    string mergeCharacters(string s, int k) {
        while (true) {
            bool merged = false;
            int n = s.size();
            for (int i = 0; i < n && !merged; ++i) {
                int limit = min(n - 1, i + k);
                for (int j = i + 1; j <= limit; ++j) {
                    if (s[j] == s[i]) {
                        s.erase(j, 1);    // merge right into left: remove j
                        merged = true;    // we must restart from left after this
                        break;
                    }
                }
            }
            if (!merged) break; // no possible merges left
        }
        return s;
    }
};