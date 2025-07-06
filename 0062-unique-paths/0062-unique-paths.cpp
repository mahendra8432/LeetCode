class Solution {
public:
    // Method 2:-Tabulation
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) return 1;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<max(m,n);i++){ 
           if(i<n) dp[0][i]=1;
           if(i<m) dp[i][0]=1;
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j]=dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[m-1][n-1];
    }
};
// value of each box is addition of value of box which is at left and at up.