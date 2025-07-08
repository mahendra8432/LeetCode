class Solution {
public:
//Method 3:Space optimization ( from end to start.)
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m=matrix.size(), n=matrix[m-1].size();
        vector<int>tempc(n,-1),tempb(n,-1);
        int curri,down,rightdown=INT_MAX,leftdown=INT_MAX,mini=1e9;
        if(m==1) return *min_element(matrix[0].begin(), matrix[0].end());
        tempb=matrix[m-1];
        for(int i=m-2;i>=0;i--){
            for(int j=n-1;j>=0;j--){
               rightdown=INT_MAX,leftdown=INT_MAX;
               down=tempb[j];
               if(j>0) leftdown=tempb[j-1];
               if(j<n-1) rightdown=tempb[j+1];
               curri=matrix[i][j] + min(down,min(leftdown,rightdown));
               tempc[j]=curri;
               if(i==0) mini=min(mini,curri);
            }
            tempb=tempc;
        }
        return mini;
    }
};
