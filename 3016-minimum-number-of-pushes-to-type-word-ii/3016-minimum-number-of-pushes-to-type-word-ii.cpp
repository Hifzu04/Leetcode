class Solution {
public:
    int minimumPushes(string word) {
        map<char, int> mpp;

        for (char ch : word) {
            mpp[ch]++;
        }

      
        vector<int> freq;
        for (auto &it : mpp) {
            freq.push_back(it.second);
        }

        
        sort(freq.begin(), freq.end(), greater<int>());

        int ans = 0;
        int factor = 1;
        int counter = 0;

        for (int x : freq) {
            counter++;

            if (counter > 24)
                factor = 4;
            else if (counter > 16)
                factor = 3;
            else if (counter > 8)
                factor = 2;
            else
                factor = 1;

            ans += x * factor;
        }

        return ans;
    }
};