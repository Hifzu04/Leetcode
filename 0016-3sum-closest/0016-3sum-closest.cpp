class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closest = 1000000;
        int n = nums.size();
        for(int i=0 ; i<=n-3 ; i++ ){  //0 1 1 1 
            int j = i+1 ;
            int k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(abs(sum-target) < abs(closest-target) ){
                    closest = sum;
                }
                if(sum < target){
                    j++;
                }else {
                    k--;
                }
            }
        }
        return closest;
    }
};

// -4 -1 1 2
// outer loop
//two pointer 