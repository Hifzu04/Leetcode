class Solution {
public:
    string trimTrailingVowels(string s) {
        string temp = s;
        string vovels = "aeiou";
        for (int i = s.size() - 1; i >= 0; i--) {
            char curr = s[i];
            bool flag = false;
            for (int i = 0; i < 5; i++) {

                if (vovels[i] == curr) {
                    temp.pop_back();
                    flag = true;
                }
            }
            if (flag == false) {
                break;
            }
        }

        return temp;
    }
};