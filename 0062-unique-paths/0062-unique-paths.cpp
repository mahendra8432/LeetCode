class Solution {
public:
    // Method 2:-Tabulation
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int left,up;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(i==0 || j==0) dp[i][j]=1;
                else{
                    left=dp[i][j-1];
                    up=dp[i-1][j];
                    dp[i][j]=left+up;
                }
            }
        }
        return dp[m-1][n-1];
    }
};
// value of each box is addition of value of box which is at left and at up.