class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int n = s.size();
        int totalchar = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != '-')
                totalchar++;
        }

        int firstgrp = totalchar % k;

        string ans = "";
        int i = 0;
        bool flag = false;
        while (firstgrp) {
            if (s[i] != '-') {
                firstgrp--;
                ans.push_back(s[i]);
                flag = true;
            }
            i++;
        }
        int p = i;
        if (flag)
            ans.push_back('-');
      
          int counter = 0;
        for (int j = p; j < n; j++) {
          
            if (s[j] != '-') {
                ans.push_back(s[j]);
                counter++;
                if (counter == k && j!= n-1) {
                    ans.push_back('-');
                    counter = 0;
                }
            }
        }

          std::transform(ans.begin(), ans.end(), ans.begin(), ::toupper);
          if(( ans.length() >1) && ans[ans.length() - 1] == '-') {
            ans.erase(ans.length() - 1); 
          }

        return ans;
    }
};

/// count all chars //count % k will be in first then rest of them will be k
/// elemet