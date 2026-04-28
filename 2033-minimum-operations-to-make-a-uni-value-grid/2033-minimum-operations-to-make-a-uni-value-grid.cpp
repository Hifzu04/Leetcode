class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m= grid[0].size();

        int base = grid[0][0];

        vector<int>vec;
        for(int i = 0 ; i<n ; i++){
            for(int j =0 ; j< m ; j++){
                if(((grid[i][j] -base ) % x) !=0){
                    return -1;
                }
                vec.push_back(grid[i][j]);
            }
        }

        sort(begin(vec) ,end(vec));

        int mid = vec[vec.size()/2];
        int diff= 0;
        for(auto x : vec){
            diff += (abs(x-mid));
        }

        return diff/x;
    }
};