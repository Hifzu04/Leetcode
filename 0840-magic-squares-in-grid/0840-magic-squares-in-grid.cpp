class Solution {
public:
   
     bool ismagic(int r , int c , vector<vector<int>>&grid){
        //check dixtint , between 1 and 9
        unordered_set<int>st;
        for(int i = r ; i< r+3 ;i++){
            for(int j = c ; j<c+3 ; j++){
                if(grid[i][j] > 9 || grid[i][j] < 1 || st.count(grid[i][j]) ){
                    return false ;
                }else {
                    st.insert(grid[i][j]);
                }
            }
        }

        int sumrow = grid[r][c] + grid[r][c+1] + grid[r][c+2];
        //check if each row and each col are equal 
        for(int i = 0 ; i <3 ; i++){
            //rowwise
            if(grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != sumrow){
                return false ;
            }
            //each col 
            if(grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i] != sumrow){
                return false ;
            }
        }
        //check diag
        if(grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != sumrow) return false ;
        //check anti diag
        if(grid[r][c+2] + grid[r+1][c+1] + grid[r+2][c] != sumrow) return false ;

        return true;
     }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0  ;

        for(int i = 0 ; i<=n-3 ; i++){
            for(int j = 0 ; j<=m-3 ; j++){
                if(ismagic(i , j , grid)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};