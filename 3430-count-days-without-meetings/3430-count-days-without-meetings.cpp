class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n=meetings.size();
        sort(meetings.begin(),meetings.end());
        int start=meetings[0][0],end=meetings[0][1],count=0;
        for(int i=1;i<n;i++){
            if(meetings[i][1]<=end) continue;
            else if(meetings[i][0]<=end && meetings[i][1]>end) end=meetings[i][1];
            else {//meetings[i][0]>end;
                   count+=meetings[i][0]-end-1;
                   start=meetings[i][0];
                   end=meetings[i][1];
            }
        }
        return count + days-end+ meetings[0][0]-1;
    }
};