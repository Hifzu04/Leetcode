class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int n = units.size();
        int m = units[0].size();
         long long sum = 0  ;
        if(m==1){
            for(auto ele : units){
                sum+= ele[0];
            }
            return sum;
        }

         long long secSmallest = LLONG_MAX;
         long long firstSmallest = LLONG_MAX;

        for(int row = 0 ; row < n ; row++){
           sort(units[row].begin() , units[row].end());

           sum += units[row][1];
           secSmallest = min((long long)units[row][1] , secSmallest);
           firstSmallest= min((long long)units[row][0] , firstSmallest);
           
        }

        return sum + firstSmallest - secSmallest;
    }
};