class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        map<string, int> mp;
        for (int i = 0; i < n; i++) {
            if (i > n - k)
                continue;
            string substr = "";
            for (int j = i; j < i + k; j++) {
                substr += s[j];
            }
            mp[substr]++;
            substr = "";
        }

             if (mp.size() == pow(2, k)) {
        return true;
    }

    return false;


          









        
    }
   

};