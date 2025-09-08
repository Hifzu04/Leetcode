class Solution {
public:
   bool valid(int a , int b){
    string sa  = to_string(a);
    string sb = to_string(b);
    for(int i = 0 ; i< sa.size() ; i++){
        if (sa[i] =='0') return false ;
        
    }
    for(int i = 0  ; i<sb.size() ; i++){
        if(sb[i]=='0') return false ;
    }
    return true;
   }
    vector<int> getNoZeroIntegers(int n) {
        vector<int>ans ; 
        
        for(int i  = 1 ; i< n  ; i++){
            int a  = i ; 
            int b  = n -i;
            if (valid(a , b)) {ans.push_back(a); ans.push_back(b) ; break;}

        }
        return ans;
        
    }
};