class Solution {
      using ll = long long;
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
         ll  p1 =  (min( 1ll * costBoth*(  max(need1 , need2)) ,1ll * cost1*need1 + 1ll * cost2*need2));
         ll  common =1ll * min(need1 ,need2) * costBoth ;
         ll rem = abs(need1-need2) ;
         ll  p2 = 0;
         if(need1>need2) {
            p2 = 1ll * rem * cost1 + common;
         }else {
            p2 = 1ll *  rem* cost2 + common ;
         }

         return min(p1, p2);

    }
};