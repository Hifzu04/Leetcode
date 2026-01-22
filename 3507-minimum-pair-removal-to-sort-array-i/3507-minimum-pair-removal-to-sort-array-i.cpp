class Solution {
public:
    
    int minimumPairRemoval(vector<int>& nums) {
        int op =0 ;
         while(true){
            if(is_sorted(nums.begin() , nums.end())){
                return op;
            }else{
                op++;
               int minm = INT_MAX;
                int minIdx= -1;
                for(int i = 1 ; i< nums.size(); i++){
                    if(nums[i-1]+ nums[i] < minm){
                        minm = nums[i-1]+ nums[i];
                        minIdx = i-1;
                    }
                }
               nums.erase(nums.begin() + minIdx);
               nums.erase(nums.begin() + minIdx);
                nums.insert(nums.begin() + minIdx, minm);


            }
         }
    }
};




/*

sort. 

*/