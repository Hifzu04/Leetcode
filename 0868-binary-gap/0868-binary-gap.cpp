class Solution {
public:
    int binaryGap(int n) {
        int prev = 1000 ; 
        int curr = 0;
        int ans = 0 ;
        while(n>0){
             
             if(n&1){
                ans = max(ans , curr-prev);
                prev = curr;
             }
             curr++;
             n>>=1;
        }

        return ans;
       
    }
};