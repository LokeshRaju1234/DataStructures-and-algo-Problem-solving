class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j,int r,int c) {
        if (i < 0 || j < 0 || i >= r || j >= c || grid[i][j] == 0) {
            return 0;
        }

        grid[i][j] = 0;
        int count = 1;
        count += dfs(grid,i - 1,j,r,c);
        count += dfs(grid,i + 1,j,r,c);
        count += dfs(grid,i,j + 1,r,c);
        count += dfs(grid,i,j - 1,r,c);
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxarea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int count = dfs(grid, i, j, n, m);
                    if (count  > maxarea) {
                        maxarea = count;
                    }
                }
            }
        }

        return maxarea;
    }
};