class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i = 0 ; i< asteroids.size() ; i++){
            int curr = asteroids[i];
          
            if(st.empty() || curr >0){
                st.push(curr);
            }else {   // curr < 0 and st has some ele
                while(!st.empty()){
                    int top = st.top();
                    if(top < 0) {
                        st.push(asteroids[i]);
                        break;
                    } 
                    if(top == abs(asteroids[i])) {
                        st.pop();
                        break; 
                    } else if(abs(asteroids[i]) < top){
                        break;
                    }else {     
                        st.pop();
                        if(st.empty()){
                            st.push(asteroids[i]);
                            break;
                        }
                    }
                }
            }
        }

        vector<int>ans ; 
        while(!st.empty()){
            int top = st.top();
            st.pop();
            ans.push_back(top);
        }
        reverse(ans.begin() , ans.end());
        return ans ;
    }
};


// 3,5,-6,2,-1,4]
//stack : 3 5  
//if (curr < 0) {
   // if st.top() > curr --> continue
   //else if st.top() < curr --> st.pop() ; 
   //else st.top == curr --> st.pop();
//}
