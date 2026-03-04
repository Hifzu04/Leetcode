class Solution {
public:
    bool checkspl(vector<vector<int>>& mat , int i , int j ){
        
        int n = mat.size();
        int m = mat[0].size();

        //check col
        for(int col = 0 ; col < m ; col++ ){
            if(col != j && mat[i][col] == 1){
                return false ;
            }
        }

        //check row
        for(int row = 0 ; row< n ; row++){
            if(row != i && mat[row][j] == 1){
                return false;
            }
        }

        return true;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0 ;
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0 ; i< n ; i++ ){
            for(int j = 0 ; j< m ; j++){
                if(mat[i][j] == 1){
                   if( checkspl(mat , i ,j)) ans++; 
                }
            }
        }

        return ans;
    }
};