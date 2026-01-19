class Solution {
public:
 int findSum(int i , int j , int digx , int digy ,vector<vector<int>>& pref){ 
           int sum =  pref[digx][digy] - (i> 0 ? pref[i-1][digy] : 0) - (j>0 ? pref[digx][j-1]: 0) + 
            ((i>0 && j>0) ? pref[i-1][j-1] : 0 );

            return sum ;
        }
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int row = mat.size();
        int col = mat[0].size();
        vector<vector<int>> pref(row, vector<int>(col, 0));

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                 pref[r][c] =  (c > 0 ? pref[r][c - 1] : 0)
                 + (r >0 ? pref[r - 1][c] :0)
                - ((r>0 && c > 0) ? pref[r - 1][c - 1] : 0 ) + mat[r][c];
            }
        }

       

        for (int size = min(row, col); size >= 1; size--) {

            for (int i = 0; i < row; i++) {
                if (i + size > row)
                    break;
                for (int j = 0; j < col; j++) {
                    if (j + size > col) break;


                int sum = findSum(i , j , i+size-1 , j+size-1 ,pref)  ;

                if(sum <= threshold)   return size;
                    

                }
            }
        }
        return 0;
    }
};