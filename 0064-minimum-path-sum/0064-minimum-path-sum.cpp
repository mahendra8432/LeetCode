class Solution {
public:
    int  fun(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&grid){
        int left,right;
        if(i<0 || j<0) return INT_MAX;
        if(i==0 && j==0) return grid[0][0];
        if(dp[i][j]!=-1) return dp[i][j];
        left  = fun(i-1,j,dp,grid);
        right = fun(i,j-1,dp,grid); 
        return  dp[i][j]= grid[i][j] + min(left,right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fun(m-1,n-1,dp,grid);
    }
};