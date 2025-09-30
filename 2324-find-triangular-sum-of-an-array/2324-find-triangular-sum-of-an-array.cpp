class Solution {
public:
    int triangularSum(vector<int>& nums) {
        if (nums.empty()) return 0;       
        if (nums.size() == 1) return nums[0];

        vector<int> temp;
        while (nums.size() > 1) {
            temp.clear();
            temp.reserve(nums.size() - 1);
            for (size_t i = 0; i + 1 < nums.size(); ++i) {
                temp.push_back((nums[i] + nums[i+1]) % 10);
            }
            nums.swap(temp); 
        }
        return nums[0];
    }
};
