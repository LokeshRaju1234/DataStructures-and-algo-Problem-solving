class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int& oldvalue,
             int& newvalue,int r,int c) {
        if (i < 0 || j < 0 || i >= r || j >= c) {
            return;
        }

        if(image[i][j] != oldvalue)
        {
           return;
        }

        image[i][j] = newvalue;

        dfs(image,i + 1,j,oldvalue,newvalue,r,c);
        dfs(image,i,j + 1,oldvalue,newvalue,r,c);
        dfs(image,i - 1,j,oldvalue,newvalue,r,c);
        dfs(image,i,j - 1,oldvalue,newvalue,r,c);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int color) {
        int n = image.size();
        int m = image[0].size();
        int oldvalue = image[sr][sc];
        int newvalue = color;
        // image[src][sr] = newvalue;
        if(oldvalue == newvalue)
        {
            return image; //edge case
        }
        dfs(image, sr,sc, oldvalue, newvalue,n,m);


        return image;
    }
};