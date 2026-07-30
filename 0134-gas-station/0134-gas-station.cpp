class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        // for(int i=0 ; i<n ; i++ ){
        //     int currfuel = gas[i];
        //     if(currfuel < cost[i]){
        //         continue;
        //     }
        //        currfuel -= cost[i];
        //     int j = (i+1)%n;
        //     while(j != i){
        //         currfuel += gas[j];
        //         if(currfuel < cost[j] || currfuel <= 0){
        //             break;
        //         }
        //         currfuel -= cost[j];
        //         j = (j+1)%n;
        //     }
        //     if(j==i){
        //         return i;
        //     }
        // }

        // return -1;
         int totgas = 0 ; 
         int totcost = 0;

        for(int i=0 ; i<n ; i++ ){
            totgas += gas[i];
            totcost += cost[i];
        }

        if(totcost > totgas){
            return -1;
        }

         int ans = 0 ;
         int tot = 0; 
         for(int i=0 ; i<n ; i++ ){
            tot += (gas[i] - cost[i]);
            if(tot < 0){
                ans = i+1; 
                tot = 0;
            }
            
         }

         return ans;

    }
};



// 1 2 3 4 5 
// 3 4 5 1 2