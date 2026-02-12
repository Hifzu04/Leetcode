class Solution {
public:
   bool check(int topele , queue<int> q){
    vector<int>left;
      while(!q.empty()){
         if(q.front() !=  topele){
            q.pop();
         }else {
            break;
         }
      }
     if(q.empty()) return true;
     return false ; 
     
   }
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int>q ;
        stack<int>st;
        int n = students.size();

        for(int i = 0 ; i < students.size() ; i++){
            q.push(students[i]);
        }


        for(int i = n-1 ; i >= 0 ; i--){
            st.push(sandwiches[i]);
        }


        while(!st.empty() && !st.empty()){
            if(check(st.top() , q)){
                return q.size();
            }
            if(q.front() == st.top()){
                q.pop();
                st.pop();
            }
           else {
            int curr = q.front();
            q.pop();
            q.push(curr);
           }



        }

        return 0 ; 


    
    }
};





