class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        pair<int,int>p={nums[0],1};
        for(int i=1;i<n;i++){
            if(nums[i]==p.first) p.second++;
            else {
                if(p.second==0) {
                    p.first=nums[i];
                    p.second++;
                }
               else p.second--;
            }
        }
        return p.first;
    }
};