class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        vector<int>r(rows,0);
        vector<int>c(cols,0);
        for(int i=0;i<rows;i++){
             for(int j=0;j<cols;j++){
                if(matrix[i][j]==0){
                    r[i]++;c[j]++;
                }
             }
        }
        for(int i=0;i<rows;i++){
             for(int j=0;j<cols;j++){
                if(r[i]>=1 || c[j]>=1){
                   matrix[i][j]=0;
                }
             }
        }

    }
};