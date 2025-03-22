class Solution {
public:
    void get(int s,vector<vector<int>> &g,int &y,vector<bool> &v){
        if(v[s])return;
        v[s] = true;
        y++;
        for(auto &i: g[s]){
            get(i,g,y,v);
        }
    }
    void solve(int s,vector<vector<int>> &g,int &x,int &y,vector<bool> &v){
        if(v[s])return;
        v[s] = true;
        for(auto &i: g[s]){
            if(g[i].size() != y)x = 0;
            solve(i,g,x,y,v);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        vector<bool> v1(n,false),v2(n,false);
        for(auto &i: edges){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
        }
        int y = 0,x=0,ans=0;
        for(int i = 0; i < n; i++){
            if(!v1[i]){
                y = -1;
                get(i,g,y,v1);
                x = 1;
                solve(i,g,x,y,v2);
                ans += x;
            }
        }
        return ans;
    }
};