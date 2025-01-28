class Solution {
public:
    int m,n;
    int solve(int i,int j,vector<vector<int>>&grid,vector<vector<bool>>&vis){
        if(i<0 || i>=m || j<0 || j>=n || vis[i][j] || !grid[i][j]){
            return 0;
        }
        int temp=grid[i][j];
        vis[i][j]=1;
        temp+=solve(i+1,j,grid,vis);
        temp+=solve(i-1,j,grid,vis);
        temp+=solve(i,j+1,grid,vis);
        temp+=solve(i,j-1,grid,vis);
        return temp;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        m=grid.size(),n=grid[0].size();
        int ans=0;
        vector<vector<bool>>vis(m,vector<bool>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] && !vis[i][j]){
                    ans=max(ans,solve(i,j,grid,vis));
                }
            }
        }
        return ans;
    }
};