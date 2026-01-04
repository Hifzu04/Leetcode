class Solution {
public:
    string largestEven(string s) {
        while(s.size()){
            char c = s[s.size()-1];
            int last = c - '0';
            if(last %2==0 ){
                   return s; 
            } 
            else {
                s.pop_back();
            }


        }
        return "";
    }
};