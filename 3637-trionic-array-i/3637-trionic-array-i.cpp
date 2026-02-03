class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return false;

        bool i1 = false, d1 = false, i2 = false;
        int idx1 = 0, idx2 = 0;

       
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                i1 = true;
                idx1 = i + 1;      
            } else {
                break;
            }
        }
        
        if (!i1 || idx1 == 0 || idx1 >= n - 1) 
            return false;

      
        for (int i = idx1; i < n - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                d1 = true;
                idx2 = i + 1;     
            } else {
                break;
            }
        }
       
        if (!d1 || idx2 <= idx1 || idx2 >= n - 1) 
            return false;

       
        for (int i = idx2; i < n - 1; i++) {
            if (nums[i] < nums[i + 1]) {
                i2 = true;
            } else {
                i2 = false;
                break;
            }
        }
      
        return i2 && (idx2 < n - 1);
    }
};
