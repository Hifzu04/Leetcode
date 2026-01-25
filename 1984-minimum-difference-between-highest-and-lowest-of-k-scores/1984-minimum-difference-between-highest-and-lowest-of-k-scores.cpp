class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int minm = INT_MAX;
        for(int i = 0 ; i< n-k+1 ; i++){
            minm = min(minm , nums[i+k-1]-nums[i])  ;
        }
        return minm;
    
    }
};


//1 2 4 5 7 9 11 18
