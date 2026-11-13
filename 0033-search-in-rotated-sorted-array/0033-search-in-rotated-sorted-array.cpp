class Solution {
public:
   int findPivot(int s , int e , vector<int>& nums){
    while(s < e){
        int mid = s +(e-s)/2; 
        if(nums[mid] > nums[e]){
            s = mid+1 ;
        }else {
                e = mid; 
        }
    }
    return s; 
   }
     
    int gettgt(int s , int e , vector<int>& nums , int target){
       while(s <= e){
         int mid = s+ (e-s) /2 ; 
         if(nums[mid] == target) {
            return mid;
         }else if (nums[mid] < target){
            s = mid +1 ;
         }else {
            e = mid -1 ;
         }
       }
       return -1 ;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int pivotidx = findPivot(0 , n-1 , nums);
        int tgt = -1 ;
        tgt  = gettgt(0 , pivotidx-1 , nums, target);
        if (tgt != -1  ){
            return tgt;
        }
        tgt = gettgt( pivotidx , n-1 , nums, target);

        return tgt ; 
    }
};


//pivot index ;  
//find (0 , pivot idx -1 ) -> binaryserach
// find(pivot idx , n-1 ); -> binary serach