class Solution {
public:
// Method 2:- Tabulation
    int minPathSum(vector<vector<int>>& grid) {
        int  left, right=0;
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                left=INT_MAX,right=INT_MAX;
                if(i>0) left=dp[i-1][j];
                if(j>0) right=dp[i][j-1];
                if(i==0 && j==0) dp[0][0]=grid[0][0];
                else dp[i][j]=grid[i][j] + min(left,right);
            }
        }
        return dp[m-1][n-1];
    }
};
// same as unique path nut insted of returning 1 in base case return value of grid array
// so it will give you some
