#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        
        
        vector<int> suffMin(n);
        suffMin[n - 1] = nums[n - 1];
        
        for (int i = n - 2; i >= 0; --i) {
            suffMin[i] = min(nums[i], suffMin[i + 1]);
        }
        
        int currentMax = nums[0];
        
        for (int i = 0; i < n; ++i) {
            currentMax = max(currentMax, nums[i]);
            
            // Instability score: max(nums[0..i]) - min(nums[i..n-1])
            int score = currentMax - suffMin[i];
            
            if (score <= k) {
                return i;
            }
        }
        
        return -1;
    }
};