// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();

//         queue<pair<int,int>>q;
//         int fresh = 0;
//         int time = 0;
//         for(int i = 0;i < n;i++)
//         {
//             for(int j = 0;j < m;j++)
//             {
//                 if(grid[i][j] == 2)
//                 {
//                     q.push({i,j});
//                 }
//                 else if(grid[i][j] == 1)
//                 {
//                     fresh++;
//                 }
//             }
//         }

//         if(fresh == 0)
//         {
//             return 0;//if no fresh oranges are there
//         }
//         int dx[] = {1,-1,0,0};
//         int dy[] = {0,0,1,-1};

//         while(q.size() > 0)
//         {
//             int levelsize = q.size();
//             while(levelsize--)
//             {
//                 pair<int,int> temp = q.front();
//                 q.pop();

//                 for(int k = 0;k < 4;k++)
//                 {
//                     int tempx = temp.first + dx[k];
//                     int tempy = temp.first + dy[k];
//                     if(tempx >= 0 && tempy >= 0 && tempx < n && tempy < m && grid[tempx][tempy] == 1)
//                     {
//                         grid[tempx][tempy] = 2;
//                         q.push({tempx,tempy});
//                         fresh--;
//                     }
//                 }
//             }

//             time++;
//         }

//         if(fresh == 0)
//         {
//             return time - 1;
//         }

//         return -1;
        
//     }
// };

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>>q;
        int fresh = 0;
        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {

                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }
                else if(grid[i][j] == 1)
                {
                    fresh++;
                }
            }
        }

        if(fresh == 0)
        {
            return 0;
        }

        int time = 0;
        vector<pair<int,int>>directions = {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                auto[row,col] = q.front();
                q.pop();

                for(auto [x,y] : directions)
                {
                    int r = row + x;
                    int c = col + y;

                    if(r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == 1)
                    {
                        q.push({r,c});
                        grid[r][c] = 2;
                        fresh--;//after rotting the orange the fresh fruit turns into rotten then we dec fresh orange size
                    }
                }
            }
            time++;//after rotting all adjacent fresh oranges
        }

        if(fresh == 0)
        {
            return time - 1;
        }

        return -1;
    }
};
