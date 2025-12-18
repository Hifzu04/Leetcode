class Solution {
   
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long op = 0;
        for(int i = 0 ; i<n ; i++){
            op +=(long long)strategy[i]*prices[i];
        }
        vector<long long>prest(n+1 , 0) , prepr(n+1 , 0);
        for(int i = 0 ; i<n ; i++){
            prest[i+1] = (long long)prest[i]+strategy[i] *prices[i];
            prepr[i+1] = (long long)prepr[i]+prices[i];
        }
        long long maxop =0;
        for(int i =0 ; i+k <= n ;i++){
            long long swindow = prest[i+k] - prest[i];
            long long right = prepr[i+k] - prepr[i+(k/2)];
            long long op = right - swindow ; 
                if(op>maxop) maxop = op ; 
        }
        return maxop+op;
        
        
    }
};