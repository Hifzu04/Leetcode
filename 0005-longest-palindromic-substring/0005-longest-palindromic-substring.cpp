class Solution {
public:
    bool checkPal(string& s, int low, int high) {
        while (low < high) {
            if (s[low] != s[high])
                return false;
            low++;
            high--;
        }
        return true;
    }
    //Method-2 , both are taking overall O(N^3)
     int p[1001][10001];
     bool checkPalMem(string& s, int low, int high) {
        if(low  > high){
          return  p[low][high] = 1 ;
        }
          if(p[low][high] != -1) return p[low][high];
        if(s[low] == s[high]){
           return  p[low][high]= checkPal(s , low+1 , high-1);
        }

        return  p[low][high]= 0;
      
    }

    string longestPalindrome(string s) {

        int n = s.size();

        int maxLen = 1, start = 0;
        memset(p , -1  , sizeof(p));

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {

                if (checkPalMem(s, i, j) && (j - i + 1) > maxLen) {
                    start = i;
                    maxLen = j - i + 1;
                }
            }
        }

        return s.substr(start, maxLen);
    }

}
;