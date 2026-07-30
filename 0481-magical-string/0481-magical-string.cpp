class Solution {
public:
    int magicalString(int n) {
        string s = "";
        if (n <= 3)
            return 1;
        s += "122";
        bool flag = true; // true measn add 1

        for (int i = 2; i < s.size() && s.size() < n; i++) {
            if (flag) {
                int cnt = s[i] - '0';
                string repeatedChar(cnt, '1');
                s += repeatedChar;

            } else {
                int cnt = s[i] - '0';
                string repeatedchar(cnt, '2');
                s += repeatedchar;
            }
            flag = !flag;
        }
        int ans = 0;
        for (int i = 0; i < s.size() && i< n; i++) {
            if (s[i] == '1') {
                ans++;
            }
        }
        return ans;
    }
};

//"1 22 11 2 1 22 1 22 11 2 11 22 ......