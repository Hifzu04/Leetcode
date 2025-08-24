class Solution {
public:
    int longestSubarray(vector<int>& nums) {
         int i = 0 ; int j = 0 ; 
         int zerocnt = 0 ;
           int currw = 0;
           int maxw = 0;
           int flag = 0 ;

        while(j<nums.size()){
          
         if(nums[j]==0){
            zerocnt++;
          
           
          }
         
           while(zerocnt>1){
               if(nums[i]==0 ) zerocnt--;
               i++;
           } 
          
        
          currw = j-i;
          maxw = max(maxw , currw);
          j++;

        } 
        return maxw;
    }
};














// class Solution {
// public:
//      //brute forcce
//     //   int findL(vector<int>&nums , int skipi){
//     //      int curr = 0 ; int tot = 0;
//     //     for(int i = 0 ; i< nums.size() ; i++){
//     //         if(i==skipi){
//     //             continue;
//     //         }
//     //         if(nums[i]==1){
//     //             curr++;
//     //             tot = max(curr, tot);
//     //         }else  curr= 0 ;
//     //   }
//     //   return tot;
//     //   }


//     // int longestSubarray(vector<int>& nums) {
//     //     int maxm = 0;

//     //     int cnt0 = 0 ;
//     //     for(int i =0 ; i<nums.size() ; i++){
//     //         if(nums[i]==0){
//     //             cnt0++;
//     //            maxm = max(maxm , findL(nums , i));
//     //         }

//     //     }
//     //     if(cnt0==0) return nums.size()-1;
//     //     return maxm;
//     // }



// };