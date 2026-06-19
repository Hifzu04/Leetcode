class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr    =   0;
        int ans = 0 ;
        for(auto& it : gain){
        curr += it ; 
        ans = max(ans , curr);

        }

        return ans ;
    }
};