class Solution {
public:
    int bfs(int row, int col, vector<vector<int>>& grid,
            vector<vector<int>>& vis) {

        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        int area = 0;

        while (!q.empty()) {
            auto curr = q.front();
            q.pop();

            int r = curr.first;
            int c = curr.second;
            area++;

            // Traverse all 4 directions
            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++) {
                int newRow = r + delRow[i];
                int newCol = c + delCol[i];

                if (newRow >= 0 && newRow < n &&
                    newCol >= 0 && newCol < m &&
                    grid[newRow][newCol] == 1 &&
                    vis[newRow][newCol] == 0) {

                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        int maxArea = 0;

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {

                if (!vis[row][col] && grid[row][col] == 1) {
                    int area = bfs(row, col, grid, vis);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea;
    }
};