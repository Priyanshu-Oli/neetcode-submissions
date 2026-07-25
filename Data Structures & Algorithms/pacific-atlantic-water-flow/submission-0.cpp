class Solution {
public:
    int n, m;

    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int row, int col,
             vector<vector<int>>& heights,
             vector<vector<int>>& vis)
    {
        vis[row][col] = 1;

        for(auto d : dir)
        {
            int nr = row + d[0];
            int nc = col + d[1];

            if(nr >= 0 && nr < n &&
               nc >= 0 && nc < m &&
               !vis[nr][nc] &&
               heights[nr][nc] >= heights[row][col])
            {
                dfs(nr, nc, heights, vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
    {
        n = heights.size();
        m = heights[0].size();

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));

        // Pacific Ocean
        for(int i = 0; i < n; i++)
            dfs(i, 0, heights, pacific);

        for(int j = 0; j < m; j++)
            dfs(0, j, heights, pacific);

        // Atlantic Ocean
        for(int i = 0; i < n; i++)
            dfs(i, m - 1, heights, atlantic);

        for(int j = 0; j < m; j++)
            dfs(n - 1, j, heights, atlantic);

        vector<vector<int>> ans;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};