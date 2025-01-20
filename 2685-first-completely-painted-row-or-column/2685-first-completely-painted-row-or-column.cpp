class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int l=arr.size();
        int c1=mat[0].size();
        int r1=l/c1;
        vector<int>c(c1,r1);
        vector<int>r(r1,c1);
        map<int,pair<int,int>>map;
        for(int i=0;i<r1;i++){
            for(int j=0;j<c1;j++){
                map[mat[i][j]]={i,j};
            }
        }
        for(int i=0;i<l;i++){
            auto p=map.find(arr[i]);
            int t1=p->second.first;
            int t2=p->second.second;
            c[t2]--;r[t1]--;
            if(c[t2]==0 || r[t1]==0) return i;
        }
        return -1;
    }
};