class Solution {
public:
// Methosd 1:- Memorization
    int fun(int i,int j,vector<vector<int>>& triangle,vector<vector<int>>& dp){
        int down,downright;
        if(i==triangle.size()-1) return triangle[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        down=fun(i+1,j,triangle,dp);
        downright=fun(i+1,j+1,triangle,dp);
        return dp[i][j] = triangle[i][j] + min(down,downright);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size(), n=triangle[m-1].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return fun(0,0,triangle,dp);
    }
};
// here start point is fixed but no end point so 0--->1
// remember ab apan start se end tak ja rahe hai.
// only one base case is when we reach at last row so just return that element.