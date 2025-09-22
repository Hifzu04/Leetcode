class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            mpp[nums[i]]++;
        }
        int maxfreq = 0;

        for (auto it : mpp) {
            if (it.second > maxfreq) {
                maxfreq = it.second;
            }
        }

        int ans = 0;
        for (auto it : mpp) {
            if (it.second == maxfreq) {
                ans += it.second;
            }
        }
        return ans ; 
    }
};