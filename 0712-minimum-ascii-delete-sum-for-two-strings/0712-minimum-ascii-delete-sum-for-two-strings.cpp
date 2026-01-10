class Solution {
public:
    int dp[1001][1001];
    int solve(string& s1, string& s2 , int i , int j){

        if(i==s1.size() && j==s2.size() ){
            return 0;
        }
        if(i==s1.size()){
            return s2[j] + solve(s1 , s2 ,i , j+1 );    
        }
         if(j==s2.size()){
            return s1[i] + solve(s1 , s2 ,i+1 , j );
            
        }
        if(dp[i][j] !=-1) return dp[i][j];
       
         if(s1[i]==s2[j]){
           return dp[i][j] =  solve(s1 ,s2, i+1, j+1);
        }
       
       int delete_i = s1[i] + solve(s1 ,s2 , i+1, j);
       int delete_j = s2[j] + solve(s1 , s2 ,i ,j+1);
       
       return dp[i][j] =  min(delete_i , delete_j);
      
    }
    int minimumDeleteSum(string s1, string s2) {
        memset(dp , -1 , sizeof(dp));
        return solve (s1, s2 , 0 , 0);
    }
};