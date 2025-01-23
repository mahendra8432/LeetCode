class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int rows=grid.size();
        int cols=grid[0].size();
        int count=0;
        vector<vector<int>>v;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==1) v.push_back({i,j});
            }
        }
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v.size();j++){
                if(i!=j && (v[i][0]==v[j][0] || v[i][1]==v[j][1])) {
                    count++;
                    break;
                    }
            }
        }
        return count;
    }
};