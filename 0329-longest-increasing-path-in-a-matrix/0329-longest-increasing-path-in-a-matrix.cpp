class Solution {
public:
 vector<vector<int>>a;
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();

        int length = 0;
        a.assign(r,vector<int>(c,-1));
        for(int i = 0; i < r;i++)
        {
            for(int j = 0; j < c;j++)
            {
               int count = dfs(matrix,i,j,r,c);
               if(count > length)
               {
                length = count;
               }
            }
        }

        return length;
    }

    int dfs(vector<vector<int>>& matrix,int i,int j,int r,int c)
    {
        int currval = matrix[i][j];
        int ans = 1;

        if(a[i][j] != -1)
        {
            return a[i][j];
        }
        if(i + 1 < r && matrix[i + 1][j] > currval)
        {
            ans = max(ans,1 + dfs(matrix,i + 1,j,r,c));
        }
        if(i - 1 >= 0 && matrix[i - 1][j] > currval)
        {
            ans = max(ans,1 + dfs(matrix,i - 1,j,r,c));
        }
        if(j + 1 < c && matrix[i][j + 1] > currval)
        {
            ans = max(ans,1 + dfs(matrix,i,j + 1,r,c));
        }
        if(j - 1 >= 0 && matrix[i][j - 1] > currval)
        {
            ans = max(ans,1 + dfs(matrix,i,j - 1,r,c));
        }
        return a[i][j] = ans;
    }
};