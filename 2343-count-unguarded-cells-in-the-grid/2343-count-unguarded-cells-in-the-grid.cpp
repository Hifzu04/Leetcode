class Solution {
public:
    void check(int r, int c, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // down
        for (int i = r + 1; i < n; i++) {
            if (grid[i][c] == 1 || grid[i][c] == 2) {
                break;
            }
        
                grid[i][c] = 3;
        }
        // up
        for (int i = r - 1; i >= 0; i--) {
            if (grid[i][c] == 1 || grid[i][c] == 2) {
                break;
            }
           
                grid[i][c] = 3;
        }
        // right
        for (int i = c+1; i < m; i++) {
            if (grid[r][i] == 1 || grid[r][i] == 2) {
                break;
            }
          
                grid[r][i] = 3;
        }
        // left
        for (int i = c-1; i >= 0; i--) {
            if (grid[r][i] == 1 || grid[r][i] == 2) {
                break;
            }
           
                grid[r][i] = 3;
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (vector<int> vec : guards) {
            int r = vec[0];
            int c = vec[1];
            grid[r][c] = 1;
            // guard = 1  ;
        }
        for (vector<int> wall : walls) {
            int r = wall[0];
            int c = wall[1];
            grid[r][c] = 2;
            // walls = 2
        }
        for (vector<int> guard : guards) {
            int r = guard[0];
            int c = guard[1];
            check(r, c, grid);
        }
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};