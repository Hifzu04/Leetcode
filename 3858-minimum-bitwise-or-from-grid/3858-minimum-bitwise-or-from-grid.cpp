class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int ans = (1<<20) -1;   //1111111111111...
        for(int i = 19 ; i>= 0 ; i--){
            int wans = ans ^ (1<<i);    //turn off ith bit (right most)
            //in each row can i have all element with ith bit off
            bool pos = true ;
            for(auto& row :grid){
                 bool sub = false;
                for(auto& x : row){
                    if((x | wans) == wans) sub = true;
                }

                if (!sub) pos = false;

            }
            if (!pos) continue;
            ans = wans; 




        }

        return ans;

    }
};