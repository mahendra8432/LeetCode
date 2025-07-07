class Solution {
public:
// Method 3:- Space Optimization
    int minPathSum(vector<vector<int>>& grid) {
        int  left, up;
        int curri,prevleft=0;
        int m=grid.size(),n=grid[0].size();
        vector<int>tempc(n,-1),tempu(n,1);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                up=INT_MAX,left=INT_MAX;
                if(i>0) up  =grid[i][j] + tempu[j];
                if(j>0) left=grid[i][j] + prevleft;
                curri=min(up,left);
                prevleft=curri;
                tempc[j]=curri;
                if(i==0 && j==0) {
                    curri=grid[0][0];
                    prevleft=curri;
                    tempc[j]=curri;
                }
            }
            tempu=tempc;
        }
        return prevleft;
    }
};
// same as unique path nut insted of returning 1 in base case return value of grid array
// so it will give you some
