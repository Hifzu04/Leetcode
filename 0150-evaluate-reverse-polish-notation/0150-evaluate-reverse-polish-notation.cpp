class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       
        stack<int> st;
      
        
        for (const auto& token : tokens) {
            if (token.size() > 1 || isdigit(token[0])) {
                st.push(stoi(token));
            } else {
                
                int secondOperand = st.top();
                st.pop();
                int firstOperand = st.top();
                st.pop();
              
                
                if (token[0] == '+') {
                    st.push(firstOperand + secondOperand);
                } else if (token[0] == '-') {
                    st.push(firstOperand - secondOperand);
                } else if (token[0] == '*') {
                    st.push(firstOperand * secondOperand);
                } else {  
                    st.push(firstOperand / secondOperand);
                }
            }
        }
      
       
        return st.top();
    }
};