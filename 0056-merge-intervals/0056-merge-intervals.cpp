class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
       });
        for(int i=1;i<intervals.size();i++){
            while(i<intervals.size() && intervals[i][0]>=intervals[i-1][0] && intervals[i][0]<=intervals[i-1][1] ){
                intervals[i]={intervals[i-1][0],max(intervals[i-1][1],intervals[i][1])};
                i++;
            }
           if(i!=intervals.size() ) ans.push_back({intervals[i-1][0],intervals[i-1][1]});
        }
         ans.push_back({intervals[intervals.size()-1][0],intervals[intervals.size()-1][1]});
        return ans;
       
    }
};