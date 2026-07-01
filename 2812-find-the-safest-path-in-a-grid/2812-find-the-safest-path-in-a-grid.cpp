class Solution {
    static constexpr int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int N = grid.size();
        vector<vector<int>> minDist = precompute(grid, N);
        priority_queue<vector<int>> maxHeap;
        vector<vector<bool>> visit(N, vector<bool>(N, false));

        maxHeap.push({minDist[0][0], 0, 0});
        visit[0][0] = true;

        while (!maxHeap.empty()) {
            vector<int> cur = maxHeap.top(); maxHeap.pop();
            int dist = cur[0], r = cur[1], c = cur[2];

            if (r == N - 1 && c == N - 1) {
                return dist;
            }

            for (const auto& dir : directions) {
                int r2 = r + dir[0], c2 = c + dir[1];
                if (inBounds(r2, c2, N) && !visit[r2][c2]) {
                    visit[r2][c2] = true;
                    int dist2 = min(dist, minDist[r2][c2]);
                    maxHeap.push({dist2, r2, c2});
                }
            }
        }
        return 0;
    }

private:
    vector<vector<int>> precompute(vector<vector<int>>& grid, int N) {
        vector<vector<int>> minDist(N, vector<int>(N, -1));
        queue<vector<int>> q;

        for (int r = 0; r < N; r++) {
            for (int c = 0; c < N; c++) {
                if (grid[r][c] == 1) {
                    q.push({r, c, 0});
                    minDist[r][c] = 0;
                }
            }
        }

        while (!q.empty()) {
            vector<int> cur = q.front();
            q.pop();
            int r = cur[0], c = cur[1], dist = cur[2];

            for (const auto& dir : directions) {
                int r2 = r + dir[0], c2 = c + dir[1];
                if (inBounds(r2, c2, N) && minDist[r2][c2] == -1) {
                    minDist[r2][c2] = dist + 1;
                    q.push({r2, c2, dist + 1});
                }
            }
        }
        return minDist;
    }

    bool inBounds(int r, int c, int N) {
        return r >= 0 && c >= 0 && r < N && c < N;
    }
};