class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>mpp;
        unordered_map<int,int>color;
        vector<int>ans;
        int distinct=0;
        for(auto &it:queries){
            int node = it[0]; int new_color = it[1];
            if(color.find(node)!=color.end()){
                int cur_color=color[node];
                mpp[cur_color]--;
                if(mpp[cur_color]==0){
                    --distinct;
                }
            }
            color[node]=new_color;
            mpp[new_color]++;
            if(mpp[new_color]==1){
                ++distinct;
            }
            ans.push_back(distinct);
        }
        return ans;
    }
};