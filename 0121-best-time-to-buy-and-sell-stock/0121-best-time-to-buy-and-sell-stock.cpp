class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = 0 ; 
      //  int sell = arr[1];
        for(int i =1 ; i<prices.size() ; i++){

              profit = max(profit , (prices[i] - buy)); 
              buy = min(prices[i]  , buy);

              
        }
        return profit ;
    }
};