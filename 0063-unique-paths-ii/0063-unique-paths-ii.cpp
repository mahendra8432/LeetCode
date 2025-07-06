class Solution {
public:
    int  fun(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&obstacleGrid){
        int left=0,right=0;
        if(i<0 || j<0) return 0;
        if(obstacleGrid[i][j]==1) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        if(obstacleGrid[i-1][j]!=1) left  = fun(i-1,j,dp,obstacleGrid);
        if(obstacleGrid[i][j-1]!=1) right = fun(i,j-1,dp,obstacleGrid); 
        return  dp[i][j]= left + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        bool flag1=true,flag2=true;
        for(int i=0;i<max(m,n);i++){
            if(i<n){
                 if(flag1 && obstacleGrid[0][i]==0) dp[0][i]=1;
                 else{
                    dp[0][i]=0;
                    flag1=false;
                 }
            }
            if(i<m){
                if(flag2 && obstacleGrid[i][0]==0) dp[i][0]=1;
                else{
                    dp[i][0]=0;
                    flag2=false;
                }
            }
        }
        return fun(m-1,n-1,dp,obstacleGrid);
    }
};