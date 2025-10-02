class Solution {
public:
    int maxBottlesDrunk(int bott, int exc) {
        int ans = 0 ;
        while(bott>=exc){
            ans+=exc;
            bott =( bott - exc +1);
            exc++;
        }
        ans+=bott;
        return ans;
    }
};