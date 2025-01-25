class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        
        // Create a vector of pairs (value, original index)
        vector<pair<int, int>> sortedNums;
        for (int i = 0; i < n; i++) {
            sortedNums.push_back({nums[i], i});
        }
        
        // Sort based on value
        sort(sortedNums.begin(), sortedNums.end());
        
        // Union-find to group swappable indices
        vector<int> parent(n);
        iota(parent.begin(), parent.end(), 0); // Initialize Union-Find
        
        function<int(int)> find = [&](int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };
        
        // Now, try to union all indices that are within the limit range
        for (int i = 1; i < n; i++) {
            if (abs(sortedNums[i].first - sortedNums[i - 1].first) <= limit) {
                int p1 = find(sortedNums[i].second);
                int p2 = find(sortedNums[i - 1].second);
                if (p1 != p2) {
                    parent[p1] = p2;
                }
            }
        }
        
        // Group all indices by their root parent
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) {
            groups[find(i)].push_back(i);
        }
        
        // Create result array
        vector<int> result(nums);
        
        // For each group, sort the values and place them back in result
        for (auto& group : groups) {
            vector<int> indices = group.second;
            vector<int> values;
            for (int idx : indices) {
                values.push_back(nums[idx]);
            }
            
            // Sort values to place them in lexicographical order
            sort(values.begin(), values.end());
            
            // Place sorted values back in the original indices
            sort(indices.begin(), indices.end());
            for (int i = 0; i < indices.size(); i++) {
                result[indices[i]] = values[i];
            }
        }
        
        return result;
    }
};
