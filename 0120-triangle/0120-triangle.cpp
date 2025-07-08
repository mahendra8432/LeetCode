class Solution {
public:
// method 2.2:- Tabulation from end to start because recursion is fron start to end.
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size(), n=triangle[m-1].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int down,rightdown=INT_MAX;
        for(int i=0;i<n;i++) dp[m-1][i]=triangle[m-1][i];
        for(int i=m-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                down=dp[i+1][j];
                rightdown=dp[i+1][j+1];
                dp[i][j]= triangle[i][j] + min(down,rightdown);
            }
        }
        return dp[0][0];
    }
};
// fill last row same as triangle's last row.
// now fill second last row based on last row. similarly foe others