class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i=0;i<numRows;i++){
            vector<int>temp;
            for(int j=0;j<=i;j++){
                if(i==j)  temp.push_back(1);
                else if(j==0)  temp.push_back(1);
                else temp.push_back(ans[i-1][j]+ans[i-1][j-1]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};