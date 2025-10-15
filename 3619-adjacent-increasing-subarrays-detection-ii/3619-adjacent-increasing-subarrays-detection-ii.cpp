class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        
       int currinc = 1 ; 
       int previnc = 0 ;
       int maxk = -1;

        for(int i = 1; i<nums.size() ; i++){
            if(nums[i]>nums[i-1]){
                currinc++;
            }else {
                previnc = currinc;
                currinc = 1 ; 
            }

            if(currinc/2 >= maxk) maxk = max(maxk , currinc/2);

            if(min(currinc , previnc) >=maxk) maxk = max(maxk , min(currinc , previnc));
        }
        return maxk;
    }
};