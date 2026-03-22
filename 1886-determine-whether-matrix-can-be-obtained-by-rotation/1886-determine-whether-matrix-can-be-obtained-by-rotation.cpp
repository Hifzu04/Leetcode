class Solution {
public:
    void rotate(vector<vector<int>>& mat) {
        // Transpose
        for (int i = 0; i < mat.size(); i++) {
            for (int j = i; j < mat.size(); j++) {
                swap(mat[i][j], mat[j][i]);
            }
        }
        //reve
        for(auto& x : mat){
            reverse(x.begin() , x.end());
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for (int i = 0; i < 4; i++) {
            if (mat == target) {
                return true;
            }
            rotate(mat);
        }

        return false;
    }
};