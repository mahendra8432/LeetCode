class Solution {
public:
   bool dfs(int node,int t,vector<int> &vis,unordered_map<int,int> &path,vector<int> adj[]){
       vis[node]=1;
       path[node]=t;
       if(node==0){
           return true;
       }
       for(auto child:adj[node]){
           if(!vis[child]){
               if(dfs(child,t+1,vis,path,adj)){
                   return true;
               }
           }
       }
       path.erase(node);
       return false;
   }


    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        vector<int> adj[n];
        for(auto it:edges){
            int x=it[0];
            int y=it[1];
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        vector<int> vis(n,0);
        unordered_map<int,int> path;
        dfs(bob,0,vis,path,adj);

        queue<vector<int>> q;
        q.push({0,0,0}); // node time tot 
        vis.assign(n,0);

        int ans=INT_MIN;
        while(!q.empty()){
            vector<int> v=q.front();
            int node=v[0];
            int time=v[1];
            int tot=v[2];
            q.pop();
            vis[node]=1;

            if(path.find(node)==path.end()){
                tot+=amount[node];
            }
            else{

                if(time<path[node]){
                    tot+=amount[node];
                }
                else if(time==path[node]){
                    tot+=(amount[node]/2);
                }
            }

            if(adj[node].size()==1 && node!=0){
                ans=max(ans,tot);
            }

            for(auto child:adj[node]){
               if(!vis[child]){
                   q.push({child,time+1,tot});
               }
            }
        }
        return ans;
    }
};