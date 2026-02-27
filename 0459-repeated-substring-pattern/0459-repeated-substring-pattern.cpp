class Solution {
public:
    bool repeatedSubstringPattern(string s) {
      
      int n = s.size();
      for(int i = 1 ; i<=n/2 ; i++){
        if(n%i==0){
            int timesAppend = n/i;
            string curr = s.substr(0, i);
            string newString = "";
            while(timesAppend--){
                newString +=curr;
            }
           if(newString == s) return true;
            
        }
      }

      return false;
    }
};