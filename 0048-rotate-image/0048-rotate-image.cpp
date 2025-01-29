class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();//column size;
        int m=matrix[0].size();//row size;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
           for(int j=0;j<m;j++){
                reverse(matrix[j].begin(),matrix[j].end());
            }

    }
};