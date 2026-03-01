class Solution {
public:
    void solve(int idx, vector<string>&digitToLetters , vector<string>&result , string temp , string digits){
          if(idx==digits.size()){
            result.push_back(temp);
            return;
          }
          char curr = digits[idx];
          string currstr = digitToLetters[curr-'0'];

          for(int i = 0  ; i< currstr.size() ; i++){
            //DO 
            temp.push_back(currstr[i]);
            solve(idx+1, digitToLetters , result , temp , digits);
            temp.pop_back();
          }



    }
    vector<string> letterCombinations(string digits) {
         vector<string> digitToLetters = {
            "",
            "",
            "abc",  
            "def",          


            "ghi",  
            "jkl",  
            "mno",  
            "pqrs", 
            "tuv",  
            "wxyz"  
        };

       // string letters = digitToLetters[digit - '2'];
        vector<string>result;
        string temp;
      solve(0,digitToLetters , result , temp , digits );
      return result;
    }
};