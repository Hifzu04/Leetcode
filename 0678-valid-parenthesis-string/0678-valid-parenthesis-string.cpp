class Solution {
public:
    int t[101][101];
    bool isvalid(string &s , int i , int count){
       if (count < 0) return false; 
        if(i==s.size()){
            return count==0;
        }
        if(t[i][count] != -1) return t[i][count];
        if(s[i]=='(') return  t[i][count] = isvalid(s , i+1 , count+1);
        else if(s[i]==')'){
            return  t[i][count]= isvalid(s , i+1 , count-1);
        } 
     
        else {
             return  t[i][count] = isvalid(s , i+1 , count+1) ||  isvalid(s, i+1 , count) ||  
              isvalid(s ,i+1 , count-1);
        }
    
        
        
    }
    bool checkValidString(string s) {
        int n = s.size();
        memset(t , -1 , sizeof(t));
        return isvalid(s , 0 ,0);
    }
};