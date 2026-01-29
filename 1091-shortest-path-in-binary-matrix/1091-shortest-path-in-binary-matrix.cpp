class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        if(mat[0][0] == 1 || mat[n - 1][n - 1] == 1)
        {
            return -1;
        }

        queue<pair<int, int>> q;
        q.push({0,0});
        mat[0][0] = 1;//mark as visited
        int length = 1;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1},{-1,-1},{-1,1},{1,-1},{1,1}};
        while (!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size;i++)
            {
                auto [row,col] = q.front();
                q.pop();

                if(row == n - 1 && col == n - 1)
                {
                    return length;
                }
                for(auto [x,y] : directions)
                {
                    int r = row + x;
                    int c = col + y;

                    if(r >= 0 && r < n && c >= 0 && c < m && mat[r][c] == 0)
                    {
                        mat[r][c] = 1;//mark as visited
                        q.push({r,c});
                    }
                }
            }

            length++;//after completing the all directions we will increase the length
        }

        return -1;
    }
};
