class Solution {
public:
    bool hasAlternatingBits(int n) {
        if (n==1) return true;
        string binstr =  "";
        while(n>0){
            binstr.push_back(n&1);
            n >>= 1;
        }

        for(int i = 1  ; i<binstr.size() ; i++){
            if(binstr[i] == binstr[i-1]){
                return false ;
            }
        }

        return true;
    }

};