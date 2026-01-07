class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;

        int maxlen = 1;

        for (int i = 0; i < n; i++) {
            unordered_set<char> st;
            st.insert(s[i]);
            int currsize = 1;

            for (int j = i + 1; j < n; j++) {
                if (st.count(s[j])) break;
                st.insert(s[j]);
                currsize++;
            }
            maxlen = max(maxlen, currsize);
        }
        return maxlen;
    }
};
