class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, int> mpp;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    mpp[board[i][j]]++;
                }
            }
            for (auto it : mpp) {
                if (it.second > 1)
                    return false;
            }
            mpp.clear();
        }
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    mpp[board[j][i]]++;
                }
            }
            for (auto it : mpp) {
                if (it.second > 1)
                    return false;
            }
            mpp.clear();
        }

        for (int boxRow = 0; boxRow < 9; boxRow += 3) {
            for (int boxCol = 0; boxCol < 9; boxCol += 3) {
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char val = board[boxRow + i][boxCol + j];
                        if (val != '.') {
                            mpp[val]++;
                        }
                    }
                }
                for (auto it : mpp) {
                    if (it.second > 1)
                        return false;
                }
                mpp.clear();
            }
        }
    return true;

    
}
};