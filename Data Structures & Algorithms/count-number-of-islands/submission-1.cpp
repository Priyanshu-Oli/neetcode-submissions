class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;

        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, -1, 0, 1};

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (grid[i][j] == '1' && !visited[i][j]) {

                    islands++;
                    visited[i][j] = true;
                    q.push({i, j});

                    while (!q.empty()) {

                        auto [x, y] = q.front();
                        q.pop();

                        for (int k = 0; k < 4; k++) {

                            int nr = x + dr[k];
                            int nc = y + dc[k];

                            if (nr >= 0 && nr < rows &&
                                nc >= 0 && nc < cols &&
                                grid[nr][nc] == '1' &&
                                !visited[nr][nc]) {

                                visited[nr][nc] = true;
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }

        return islands;
    }
};