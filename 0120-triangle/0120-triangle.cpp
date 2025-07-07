class Solution {
public:
// method 2:- Space optiization
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size(), n=triangle[m-1].size();
        vector<int>tempc(n,-1),tempu(n,-1);
        if(m==1 && n==1) return triangle[0][0];
        int up,upleft;
        int mini=INT_MAX,curri;
        for(int i=0;i<m;i++){
            for(int j=0;j<=i;j++){
                up=INT_MAX,upleft=INT_MAX;
                if(i>0 && i!=j) up=tempu[j];
                if(j>0 && i>0) upleft=tempu[j-1];
                if(i==0 && j==0){
                  curri=triangle[0][0];
                  tempc[j]=curri;
                }
                else {
                    curri=triangle[i][j] + min(up,upleft);
                    tempc[j]=curri;
                }
                if(i==m-1) mini=min(mini,curri);
            }
            tempu=tempc;
        }
        return mini;
    }
};
// the value of any box in dp is min (of box which is up and upleft) + tringle[i][j];
// if i==j then value of any box in dp is box which is upleft + tringle[i][j];
// if j==0  then value of any box in dp is box which is up + tringle[i][j];