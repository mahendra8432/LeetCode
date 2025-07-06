class Solution {
public:
//Method 1:- Memorization
    int  fun(int i,int j,vector<vector<int>>&dp){
        int left,right;
        if(i<0 || j<0) return 0;
        if(i==0 || j==0) return 1;
        if(i==1 && j==0) return 1;
        if(i==1 && j==1) return 2;
        if(dp[i][j]!=-1) return dp[i][j];
        left  = fun(i-1,j,dp);
        right = fun(i,j-1,dp); 
        return  dp[i][j]= left + right;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fun(m-1,n-1,dp);
    }
};