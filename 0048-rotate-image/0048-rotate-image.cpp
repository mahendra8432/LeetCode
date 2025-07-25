class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int r=matrix.size();//no. of rows
        int c=matrix[0].size();//no of columns
        for(int i=0;i<r;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<r;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};