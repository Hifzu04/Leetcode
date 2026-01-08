class Solution {
//ref from codestorywithMIK
public:
    int n ;
    bool isDuplicate(string s1 , string s2){
        vector<int>c(26 , 0);
        for(char& ch : s1 ){
            //for s1 =  aa ,bb 
            if(c[ch -'a'] > 0) return true;

            c[ch-'a']++;
        }

        for(char& ch : s2){
            if(c[ch-'a'] > 0){
                return true;
            }
        }
        return false ;
    }
    int allpath(vector<string>&arr , int i , string temp){
        //base case 
        if(i==n){
           return temp.length();
        }

        //exclude
        int exclude = allpath(arr , i+1 , temp);
        //include only when there is no duplicate 
         int include  = 0;
        if(!isDuplicate(arr[i] , temp)){
           
            include = allpath(arr , i+1, temp+arr[i]);
         }
         return max(include, exclude);

    }
    int maxLength(vector<string>& arr) {
        string temp = "";
         n = arr.size();
        return allpath(arr ,  0 ,temp);
    }
};