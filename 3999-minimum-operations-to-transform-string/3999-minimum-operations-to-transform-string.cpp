class Solution {
public:
    int minOperations(string s) {
        int ans = 0 ;
        for(int i = 0 ; i<s.size() ; i++){
            if(s[i]!= 'a')
            ans = max(ans , 'z'-s[i]+1);
        }
     
        return ans;
    }
};