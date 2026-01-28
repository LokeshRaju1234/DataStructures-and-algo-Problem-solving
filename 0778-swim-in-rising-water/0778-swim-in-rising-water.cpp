class Solution {
public:
bool dfs(vector<vector<int>>& grid,vector<vector<bool>>&visited,int i,int j,int t)
{
int n = grid.size();
if(i < 0 || j < 0 || i >= n || j >= n || visited[i][j] == true || grid[i][j] > t)
{
    return false;
}

if(i == n - 1 && j == n - 1)
{
    return true;
}

visited[i][j] = true;

return dfs(grid,visited,i + 1,j,t) ||
dfs(grid,visited,i - 1,j,t) ||
dfs(grid,visited,i,j + 1,t) || 
dfs(grid,visited,i,j - 1,t);
}
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int l = 0,h = n * n;

        while(l < h)
        {
            int mid = l + (h - l) / 2;
            vector<vector<bool>>visited(n,vector<bool>(n,false));

            if(dfs(grid,visited,0,0,mid))
            {
                h = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        return l;
    }
};