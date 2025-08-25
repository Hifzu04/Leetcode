class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size(); int m = mat[0].size();
        vector<int>ans;
        int i =0 ;int  j = 0;
        bool up = true;
        while(ans.size() != m*n){
            if(up){
                while(i>=0 && j <m){
                    ans.push_back(mat[i][j]);
                    i--;
                    j++;
                }
                if(j==m){
                    j--;
                    i+=2;
                }else {
                    i++;
                }
                up =false ;
            }else {
                while(j>=0 && i<n ){
                    ans.push_back(mat[i][j]);
                    i++;  j--;
                }
                if(i==n ){
                    j+=2;
                    i--;
                }else {
                    j++;
                }
                up = true;
            }

        }
        return ans ;
    }
};