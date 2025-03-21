class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,int> indegree;
        unordered_map<string,vector<string>> adj;
        int n = ingredients.size();
        for(int i=0;i<n;i++){
            for(auto s : ingredients[i]){
                adj[s].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
   
        queue<string> q;
        for(auto it : supplies){
            q.push(it);
        }
        vector<string> ans;
        while(q.empty() == false){
            string  node = q.front();
            q.pop();
            for(auto adjnode : adj[node]){
                indegree[adjnode]--;
                if(indegree[adjnode] == 0){
                    q.push(adjnode);
                }
            }
        }


        for(string r : recipes){
            if(indegree[r] == 0){
                ans.push_back(r);
            }
        }
        return ans;
    }
};