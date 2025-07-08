class Solution {
public:
//Method 2:Tabulation ( fill dp from end to start.)
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[m-1].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        int down,rightdown=INT_MAX,leftdown=INT_MAX,mini=INT_MAX;
        if(m==1) return *min_element(matrix[0].begin(), matrix[0].end());
        for(int i=0;i<n;i++) {
            dp[m-1][i]=matrix[m-1][i];
        }
        for(int i=m-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                rightdown=INT_MAX,leftdown=INT_MAX;
                down=dp[i+1][j];
                if(j<n-1) rightdown=dp[i+1][j+1];
                if(j>0) leftdown=dp[i+1][j-1];
                dp[i][j]= matrix[i][j] + min(down,min(rightdown,leftdown));
                if(i==0) mini=min(mini,dp[0][j]);
            }
        }
        return mini;
    }
};
