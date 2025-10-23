class Solution {
public:

    bool f(string s){
        int n   = s.size();
        while(n>2){
        for(int i = 0 ; i< s.size()-1 ; i++){
                 s[i]= (((s[i]-'0') + (s[i+1]-'0'))%10)+'0';

        }
        n--;
        }

       return s[0]==s[1];

    }
    bool hasSameDigits(string s) {
        return f(s) ;
    }
};