class Solution {
public:
    string reverseByType(string s) {
        string ncharacter = "";
        string splchar = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] <= 'z' && s[i] >= 'a') {
                ncharacter += s[i];
            } else {
                splchar += s[i];
            }
        }
        int charidx = ncharacter.size()-1;
        int splcharidx = splchar.size()-1;
        
        for (int i = 0; i < s.size(); i++) {
             if (s[i] <= 'z' && s[i] >= 'a') {
                s[i] = ncharacter[charidx];
                charidx--;
             }else {
                s[i] = splchar[splcharidx];
                splcharidx--;
             }
        }

        return s;
    }
};