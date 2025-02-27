class Solution {
public:
    unordered_map<int, int> index_map;
    int findLongestSub(vector<int>& arr, int n, int i, int j, vector<vector<int>>& dp) {
        if (j >= n) return 0; 

        if (dp[i][j] != -1) return dp[i][j]; 

        int take = 0;
        int next_val = arr[i] + arr[j];
        if (index_map.find(next_val) != index_map.end()) {
            int next_index = index_map[next_val]; 
            take = 1 + findLongestSub(arr, n, j, next_index, dp);
        }
        return dp[i][j] = take;
    }

    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0; 
        vector<vector<int>> dp(n, vector<int>(n, -1)); 
        for (int i = 0; i < n; i++) {
            index_map[arr[i]] = i;
        }

        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int len = 2 + findLongestSub(arr, n, i, j, dp);
                maxLength = max(maxLength, len);
            }
        }
        if(maxLength==2) return 0;
        return maxLength;
    }
};
