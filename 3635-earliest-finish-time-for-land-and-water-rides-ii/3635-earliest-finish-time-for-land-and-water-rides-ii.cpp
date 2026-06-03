class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        //case1 land --> water
        int minlandtime  =INT_MAX;
        int ans1 = INT_MAX;
        //case2 water then land
        int minWatertime = INT_MAX;
        int ans2 = INT_MAX;
        
        for(int i = 0; i < landStartTime.size() ; i++) {
            minlandtime = min (landStartTime[i] + landDuration[i] , minlandtime);
        }
        
        for(int i =0 ; i< waterStartTime.size() ; i++){
            ans1 = min(max(waterStartTime[i]  , minlandtime ) + waterDuration[i] , ans1 );
            minWatertime = min(waterStartTime[i] + waterDuration[i] , minWatertime);
        }

         for(int i =0 ; i< landStartTime.size() ; i++){
            ans2 =  min(ans2 ,( max(landStartTime[i]  , minWatertime )) + landDuration[i]);
           
        }



        return  min (ans1 ,ans2);
    }
};