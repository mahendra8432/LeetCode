class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();    // rows
        int n = isWater[0].size(); // columns
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> distance(m, vector<int>(n, 0));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    visited[i][j] = 1;
                    q.push({{i, j}, 0});
                }
                else visited[i][j]=0;
            }
        }

        int dr[] = {0, 0, -1, 1};
        int dc[] = {-1, 1, 0, 0};
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            distance[row][col] = steps;
            for (int i = 0; i < 4; i++) {
                int nrow = row + dr[i];
                int ncol = col + dc[i];
                if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                    visited[nrow][ncol] == 0) {
                    visited[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, steps + 1});
                }
            }
        }
        return distance;
        
    }
};