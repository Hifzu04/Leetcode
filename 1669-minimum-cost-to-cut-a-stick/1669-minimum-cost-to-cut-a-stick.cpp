class Solution {
public:
    int f(vector<int> &cuts , int s , int e ,  vector<vector<int>>&dp ){
        if(e-s < 2){
            return 0;
        }
        if(dp[s][e] != -1) return dp[s][e];
        int minm = INT_MAX;
        for(int i = s+1 ;i<e; i++){
            int cost = (cuts[e]-cuts[s]) + f(cuts , s , i ,dp) + f(cuts , i , e ,dp);
            minm = min(minm , cost);
        }
        return dp[s][e] =  minm;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin() , cuts.end());
        cuts.insert(begin(cuts)  , 0 );
        cuts.push_back(n);
         int m = cuts.size();                         
        vector<vector<int>> dp(m, vector<int>(m, -1));
       return f(cuts ,  0  , cuts.size()-1 ,dp); 
    }
};