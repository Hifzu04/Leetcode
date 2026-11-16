class Solution {
public:
    int t[101];
    int f(string& s, int i, int n) {

             if(t[i] != -1){
            return t[i];
        }
        if (i == n) {
            return t[i] =  1;
        }

   
     
        if (s[i] == '0') {
            return 0;
        }

        int res = f(s, i + 1, n);

        if (i + 1 < n) {
            if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')) {
                res += f(s, i + 2, n);
            }
        }
        return t[i] =  res;
    }
    int numDecodings(string s) {
        int n = s.size();
        memset(t , -1 , sizeof(t));
        return f(s, 0, n);
    }
};

// 11106  --> A A 11 10 6 1 1 10 6

// 12 --> 1 2 || 12

// 226 -> 2 2 6  , 22 6 , 2 26
// //