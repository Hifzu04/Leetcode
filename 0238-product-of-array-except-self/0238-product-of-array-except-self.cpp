class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>leftp(n ,1);
        vector<int>rightp(n ,1);
        leftp[0] = nums[0];
        rightp[n-1] = nums[n-1];
        for(int i = 1 ; i< n ; i++){
                leftp[i] = nums[i] * leftp[i-1];  //1 2  6 24
        }
        for(int i = n-2 ; i >= 0 ; i--){
            rightp[i] = nums[i] * rightp[i+1];    
        }
       vector<int>ans(n ,1);
        for(int i = 0 ; i< n ; i++){
            if(i==0){
                ans[0] = rightp[i+1];
            }else if(i== n-1){
                ans[n-1] = leftp[n-2];
            }else {
                ans[i] = leftp[i-1] * rightp[i+1];
            }
          
        }
        return ans;
    }
};