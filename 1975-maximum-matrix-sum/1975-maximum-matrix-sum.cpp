class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n   = matrix.size();
        int m  = matrix[0].size();
        int maxm = INT_MIN;
         long long  totsum = 0;
        int cntNeg = 0 ;
        int minm =  INT_MAX;
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m  ; j++){
              
                if(matrix[i][j]<=0) {
                    cntNeg++;totsum +=(matrix[i][j]*-1);
                     maxm = max(maxm , matrix[i][j]);
                }else {
                    totsum +=matrix[i][j]; 
                    minm = min(minm , matrix[i][j]);
                }

            }
        }
        if(cntNeg %2 ) return totsum+2*(max(maxm , -1*minm));
        else return totsum;
    }
};