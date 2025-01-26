class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        // Return the maximum of the largest cycle or the sum of mutual favorite chains
        return max(maxCycle(favorite), topologicalSort(favorite));
    }

    // Function to find the size of the largest cycle in the graph
    int maxCycle(vector<int>& fa) {
        int n = fa.size();
        vector<bool> vis(n); // Visited array to track visited nodes
        int ans = 0; // Stores the size of the largest cycle
        for (int i = 0; i < n; ++i) {
            if (vis[i]) continue; // Skip already visited nodes
            vector<int> cycle; // Track the current path of nodes
            int j = i;
            // Traverse the graph until a cycle is detected
            while (!vis[j]) {
                cycle.push_back(j);
                vis[j] = true; // Mark the current node as visited
                j = fa[j]; // Move to the favorite person
            }
            // Detect and calculate the cycle size
            for (int k = 0; k < cycle.size(); ++k) {
                if (cycle[k] == j) { // Found the start of the cycle
                    ans = max(ans, (int)cycle.size() - k); // Update the largest cycle size
                    break;
                }
            }
        }
        return ans; // Return the size of the largest cycle
    }

    // Function to calculate the size of chains leading to mutual favorites
    int topologicalSort(vector<int>& fa) {
        int n = fa.size();
        vector<int> indeg(n); // In-degree array to track incoming edges
        vector<int> dist(n, 1); // Distance array to track chain lengths (initialized to 1)
        
        // Calculate in-degrees for all nodes
        for (int v : fa) ++indeg[v];
        
        // Queue for processing nodes with in-degree 0
        queue<int> q;
        for (int i = 0; i < n; ++i)
            if (indeg[i] == 0) q.push(i);
        
        // Process nodes in topological order
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            // Update the distance for the favorite person
            dist[fa[i]] = max(dist[fa[i]], dist[i] + 1);
            // Reduce the in-degree of the favorite person
            if (--indeg[fa[i]] == 0) q.push(fa[i]);
        }
        
        int ans = 0;
        // Sum up chain lengths for mutual favorite pairs
        for (int i = 0; i < n; ++i)
            if (i == fa[fa[i]]) // Check if i and fa[i] are mutual favorites
                ans += dist[i];
        return ans; // Return the total size of the chains
    }
};
