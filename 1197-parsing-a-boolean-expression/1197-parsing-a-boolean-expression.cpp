class Solution {
public:
    char parse(vector<char>vec , char op){
        if(op=='!'){
            return vec[0] == 'f' ? 't' : 'f';
        }
        if(op == '|'){
            for(int i = 0 ; i<vec.size() ; i++ ){
                if(vec[i] == 't'){
                    return 't';
                }
            }
            return 'f';
        }
         if(op == '&'){
            for(int i = 0 ; i<vec.size() ; i++ ){
                if(vec[i] == 'f'){
                    return 'f';
                }
            }
            return 't';
        }
        return 't';
    }
    bool parseBoolExpr(string s) {
        int n = s.size();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == ',')
                continue;
            if (s[i] == ')') {
                vector<char> vec;
               // st.pop();
                while(st.top() != '('){
                    vec.push_back(st.top());
                    st.pop();
                }
                st.pop();  // removing (
                char op = st.top();
                st.pop();
                st.push(parse(vec , op));



            } else {
                st.push(s[i]);
            }
        }
        return st.top() ==  'f' ? false : true;
    }
};