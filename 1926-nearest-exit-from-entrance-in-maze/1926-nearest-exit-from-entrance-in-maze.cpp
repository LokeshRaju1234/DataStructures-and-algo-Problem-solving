class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
       int n = maze.size();
       int m = maze[0].size();

       queue<pair<int,int>>q;
       q.push({entrance[0],entrance[1]});
       maze[entrance[0]][entrance[1]] = '+';
       vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
       int ans = 0;
       while(!q.empty())
       {

        int size = q.size();
        for(int i = 0;i < size;i++)
        {
            auto [row,col] = q.front();
            q.pop();

            for(auto [x,y] : directions)
            {
                int r = row + x;
                int c = col + y;

                if(r >= 0 && r < n && c >= 0 && c < m && maze[r][c] == '.')
                {
                    if(r == 0 || c == 0 || r == n - 1 || c == m - 1)
                    {
                        return ans + 1;
                    }
                    q.push({r,c});
                    maze[r][c] = '+';
                }
            }
        }

        ans++;
       }

       return -1;
    }
};