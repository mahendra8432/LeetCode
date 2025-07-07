class Solution {
public:
// method 2:- Tabulation
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size(), n=triangle[m-1].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        if(m==1 && n==1) return triangle[0][0];
        int up,upleft;
        int mini=INT_MAX;
        dp[0][0]=triangle[0][0];
        for(int i=0;i<m;i++){
            for(int j=0;j<=i;j++){
                up=INT_MAX,upleft=INT_MAX;
                if(i==0 && j==0) continue;
                if(i>0 && i!=j) up=dp[i-1][j];
                if(j>0 && i>0) upleft=dp[i-1][j-1];
                dp[i][j]=triangle[i][j] + min(up,upleft);
                if(i==m-1) mini=min(mini,dp[m-1][j]);
            }
        }
        return mini;
    }
};
// the value of any box in dp is min (of box which is up and upleft) + tringle[i][j];
// if i==j then value of any box in dp is box which is upleft + tringle[i][j];
// if j==0  then value of any box in dp is box which is up + tringle[i][j];