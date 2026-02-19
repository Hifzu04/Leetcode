class Solution {
public:
    int countBinarySubstrings(string s) {
        int prevcount = 0 ; 
        int currcount =1; 
        int n = s.size();
        int ans = 0;
        for(int i = 1 ; i< n ; i++){
            if(s[i] ==s[i-1]){
                currcount++;
            }else  {
                ans += min(prevcount  , currcount);
                prevcount = currcount;
                currcount = 1;
            }
        }
        return ans + min(prevcount,currcount );
    }
};