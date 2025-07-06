class Solution {
public:
// Method 1:- Memorization updated
    int  fun(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&obstacleGrid){
        int left=0,right=0;
        if(i<0 || j<0) return 0;
        if(obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        left  = fun(i-1,j,dp,obstacleGrid);
        right = fun(i,j-1,dp,obstacleGrid); 
        return  dp[i][j]= left + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fun(m-1,n-1,dp,obstacleGrid);
    }
};