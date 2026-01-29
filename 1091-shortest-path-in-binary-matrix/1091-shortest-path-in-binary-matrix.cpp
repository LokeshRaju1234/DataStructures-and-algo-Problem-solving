class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // blocked start or end
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        queue<pair<int,int>> q;
        q.push({0, 0});
        grid[0][0] = 1;   // mark visited
        int steps = 1;

        int dr[8] = {-1,-1,-1,0,0,1,1,1};
        int dc[8] = {-1,0,1,-1,1,-1,0,1};

        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto [r, c] = q.front();
                q.pop();

                if (r == n-1 && c == n-1)
                    return steps;

                for (int i = 0; i < 8; i++) {
                    int nr = r + dr[i];
                    int nc = c + dc[i];

                    if (nr >= 0 && nc >= 0 && nr < n && nc < n &&
                        grid[nr][nc] == 0) {

                        grid[nr][nc] = 1; // mark visited
                        q.push({nr, nc});
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};
