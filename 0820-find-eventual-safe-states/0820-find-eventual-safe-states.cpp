class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> adj[n];
        vector<int> indegree(n, 0);
        
        // Reverse the graph and compute in-degrees
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                adj[graph[i][j]].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int> q;

        // Enqueue nodes with zero in-degree
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        vector<int> ans;

        // Perform topological sorting
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        // Sort the result
        sort(ans.begin(), ans.end());
        return ans;
    }
};