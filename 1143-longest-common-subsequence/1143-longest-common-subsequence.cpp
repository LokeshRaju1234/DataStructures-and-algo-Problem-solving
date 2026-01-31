class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int r = text1.size();
        int c = text2.size();

        vector<vector<int>>dp(r + 1,vector<int>(c + 1,0));

        for(int i = 1;i <= r;i++)
        {
            for(int j = 1;j <= c;j++)
            {
                if(text1[i - 1] == text2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i][j - 1],dp[i - 1][j]);
                }
            }
        }

        return dp[r][c];
    }
};