class Solution {
public:
    int minimumDeletions(string s) {
       int n = s.size();
       int count = 0 ; 
       stack<char>st;
       for(int i = 0 ; i<s.size() ; i++){
          if(!st.empty() && st.top() == 'b' && s[i]=='a' ){
            count++;
            st.pop();
          }else {
            st.push(s[i]);
          }
       }
       return count ; 
    }
};