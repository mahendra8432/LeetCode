class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size(),p,q;
        vector<int>arr(n*n+1,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr[grid[i][j]]++;
                if(arr[grid[i][j]]==2)  q=grid[i][j];
            }
        }
        for(int i=1;i<=n*n;i++) {
            if(arr[i]==0){ p=i;break;}
            
            }
            return {q,p};
    }
};