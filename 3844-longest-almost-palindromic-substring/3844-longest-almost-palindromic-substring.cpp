class Solution {
public:
    int almostPalindromic(string s) {
        int n = s.size();
        int ans = 2;
        for (int i = 0; i < n; i++) {
            // for odd length
           int  l = 1;
          int  skip = 1;
            // skip left
            int j = i-1;
            int k = i+1;
             while (j >= 0 || k < n) {
                if (j >= 0 && k < n && s[j] == s[k]) {
                    l += 2;
                    j-- ; k++;
                } else if (skip) {
                    skip--;
                    l++;
                    j--; // skip left
                } else {
                    break;
                }
               
            }

            ans = max(ans, l);
            j = i-1;
            k = i+1;
            skip = 1;
            l = 1;
            while (j >= 0 || k < n) {
                if (j >= 0 && k < n && s[j] == s[k]) {
                    l += 2;
                     j-- ; k++;
                } else if (skip) {
                    skip--;
                    l++;
                    k++; // skip right
                } else {
                    break;
                }
               
            }
            ans= max(ans , l);

           //for  even lengthh
           j =i ; k = i+1;
           l = 0;
           skip = 1;

             while (j >= 0 || k < n) {
                if (j >= 0 && k < n && s[j] == s[k]) {
                    l += 2;
                     j-- ; k++;
                } else if (skip) {
                    skip--;
                    l++;
                    k++; // skip right
                } else {
                    break;
                }
               
            }
            ans= max(ans , l);
            


          j =i ; k = i+1;
           l = 0;
           skip = 1;

         while (j >= 0 || k < n) {
                if (j >= 0 && k < n && s[j] == s[k]) {
                    l += 2;
                    j-- ; k++;
                } else if (skip) {
                    skip--;
                    l++;
                    j--; // skip left
                } else {
                    break;
                }
                
            }

            ans= max(ans , l);
           



        }



        return ans;

        
    }
};