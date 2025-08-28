class Solution {
public:
     void helper(int row ,int col , vector<vector<int>>&grid , bool inc){
        vector<int>vec;
            int i = row ; int j = col;
        while(i < grid.size() && j<grid.size() ){
            vec.push_back(grid[i][j]);
            i++;j++;
        }
        if(!inc)
        sort(rbegin(vec) , rend(vec));
        else 
        sort(vec.begin() , vec.end());

        i  = row ; j = col;
        for(int ele : vec){

            grid[i][j] = ele;
            i++;
            j++;
        }


     }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        //for lt 
        for(int row =0  ; row<n ; row++ ){
            helper(row ,0, grid , false );
        }

        //for ut 
        for(int col = 1 ; col<grid.size() ; col++){
            helper(0 , col , grid , true);
        }


        return grid;
    }
};