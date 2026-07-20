class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int n = grid.size();
        int m = grid[0].size();

        vector<int> arr;

        // Step 1: Flatten
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                arr.push_back(grid[i][j]);
            }
        }

        int total = arr.size();
        k %= total;

        // Step 2: Rotate
        vector<int> rotated(total);

        for (int i = 0; i < total; i++) {
            rotated[(i + k) % total] = arr[i];
        }

        // Step 3: Convert back
        vector<vector<int>> ans(n, vector<int>(m));

        int idx = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = rotated[idx++];
            }
        }

        return ans;
    }
};