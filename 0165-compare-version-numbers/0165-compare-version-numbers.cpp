class Solution {
public:
    vector<string> gett(string version) {
        stringstream ss(version);
        string token = "";
        vector<string> tokens;
        while (getline(ss, token, '.')) {
            tokens.push_back(token);
        }
        return tokens;
    }

    int compareVersion(string version1, string version2) {
        vector<string> token1 = gett(version1);
        vector<string> token2 = gett(version2);

        int n = token1.size();
        int m = token2.size();
        int i = 0;
        while (i < m || i < n) {
            int a = i < n ? stoi(token1[i]) : 0;
            int b = i < m ? stoi(token2[i]) : 0;
            if (a < b) {
                return -1;
            } else if (a > b) {
                return 1;
            } else {
                i++;
            }
        }
        return 0;
    }
};