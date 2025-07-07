class Solution {
public:
// Methosd 1:- Memorization
    int fun(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        int up,upleft;
        if(i==0 && j==0) return triangle[0][0];
        if(i<0 || j<0 ) return INT_MAX;
        if(j>i) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        up=fun(i-1,j,triangle,dp);
        upleft=fun(i-1,j-1,triangle,dp);
        return dp[i][j] = triangle[i][j] + min(up,upleft);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size(), n=triangle[m-1].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int ans,mini=INT_MAX;
        for(int i=0;i<n;i++) {
          ans= fun(m-1,i,triangle,dp);
          mini=min(ans,mini);
        }
        return mini;
    }
};