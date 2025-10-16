class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();

       
        vector<int> freq(value, 0);
        for (int i = 0; i < n; ++i) {
            int r = nums[i] % value;
            if (r < 0) r += value; 
            freq[r]++;
        }

  
        int m = 0;
        while (true) {
            int r = m % value;
            if (freq[r] == 0) return m;
            freq[r]--;
            ++m;
        }

        return -1;
    }
};
