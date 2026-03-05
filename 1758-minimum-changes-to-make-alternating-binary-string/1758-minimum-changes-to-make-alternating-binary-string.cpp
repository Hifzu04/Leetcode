class Solution {
public:
    int minOperations(string s) {
        int ans1 = 0 ;
        int ans2 = 0;
        char check = '1';
        for(int i = 0; i<s.size() ; i++){
            if(s[i] != check){
               ans1++;
            }
            if(check=='0') check = '1';
            else check  = '0';
            
        }
        check = '0';
        for(int i = 0; i<s.size() ; i++){
            if(s[i] != check){
               ans2++;
            }
            if(check=='0') check = '1';
            else check  = '0';
            
        }
        return min(ans1,ans2); 
    }
};


