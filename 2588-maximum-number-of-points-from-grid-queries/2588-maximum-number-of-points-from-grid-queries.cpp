class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int r = grid.size(), c = grid[0].size();
        int n = queries.size();
        vector<vector<bool>> vis(r, vector<bool>(c));
        vector<pair<int, int>> queryIndices;
        for(int i = 0;i<n;i++){
            queryIndices.push_back({queries[i], i});
        }
        sort(queryIndices.begin(), queryIndices.end());
        int x, y, nx, ny;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        int cnt = 0;
        vector<int> res(n);
        vis[0][0] = true;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});
        for(auto[q, qi]: queryIndices){
            while(!pq.empty() and pq.top().first < q){
                x = pq.top().second.first;
                y = pq.top().second.second;
                pq.pop();
                cnt++;
                for(int j = 0;j<4;j++){
                    nx = x + dx[j];
                    ny = y + dy[j];
                    if(nx < 0 or ny < 0 or nx > r-1 or ny > c-1 or vis[nx][ny])
                        continue;
                    vis[nx][ny] = true;
                    pq.push({grid[nx][ny], {nx, ny}});
                }
            }
            res[qi] = cnt;
        }
        return res;
    }
};