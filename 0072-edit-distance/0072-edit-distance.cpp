class Solution {
public:
   int f(string& s1 , string& s2, int i , int j  ,vector<vector<int>>&dp){
           if(i>= s1.size()){
            return s2.size()-j;
           }if(j>=s2.size()){
             return s1.size()-i;
           }
           if(dp[i][j] != -1 ) return dp[i][j];

             if(s1[i] ==s2[j]) return f(s1 , s2 , i+1 , j+1 ,dp);
           int ins = 1+f(s1, s2,i,j+1 , dp);
           int del = 1+ f(s1 ,s2, i+1 , j ,dp);
           int rep = 1+f(s1 , s2, i+1 , j+1 , dp);
           return dp[i][j] =  min({ins , del ,rep});
   }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size() , vector<int>(word2.size() , -1));
        return f(word1, word2, 0 ,0,dp);

    }
};