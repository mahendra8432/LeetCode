class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        int idx = -1;
        int val = 0;
        vector<int> inc(n + 1, 0);
        for(int i = 0; i < n; i++) {
            val += inc[i];
            if(val >= nums[i]) {
                continue;
            }
            while(idx + 1 < q && val < nums[i]) {
                idx++;
                inc[queries[idx][0]] += queries[idx][2];
                inc[queries[idx][1] + 1] -= queries[idx][2];
                if(queries[idx][0] <= i && i <= queries[idx][1]) {
                    val += queries[idx][2];
                }
            }
            if(val < nums[i]) {
                return -1;
            }
        }
        return idx + 1;
    }
};