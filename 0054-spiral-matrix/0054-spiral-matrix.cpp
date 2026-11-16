class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        int m = matrix.size();
         int strow = 0 ; int  endrow = m-1 ; 
         int stcol = 0 ;
         int endcol = n-1 ;
         vector<int>ans; 

         while(ans.size() < m*n) {
            for(int i = stcol ; i<=endcol && ans.size() < m*n ; i++){
                ans.push_back(matrix[strow][i]);
            }
            for(int i = strow+1 ; i<=endrow && ans.size() < m*n  ; i++){
                ans.push_back(matrix[i][endcol]);
            }

            for(int i = endcol-1 ; i>= stcol && ans.size() < m*n  ; i--){
                ans.push_back(matrix[endrow][i]);

            }

            for(int i = endrow -1 ; i>= strow +1 && ans.size() < m*n  ; i--){
                ans.push_back(matrix[i][stcol]);
            }

            stcol++ ; endcol--; strow++; endrow--; 
         }

         return ans ; 
    }
};






