class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int p = -1;
        int n =  nums.size(); 
        for(int i = n-2 ; i >= 0 ; i--){         //[1,3,2]  
            if(nums[i] < nums[i+1]){
               
                p = i;
               
                break;
            } 
        }

          if(p != -1) {
            for(int i = n - 1; i > p; i--) {
                if(nums[i] > nums[p]) {
                    swap(nums[i], nums[p]);
                    break;
                }
            }
        }

         // if(p == -1 ) { sort(nums.begin() , nums.end()); return ; 

         
           sort(nums.begin()+p+1, nums.end());

        
        
        return;
    }
};