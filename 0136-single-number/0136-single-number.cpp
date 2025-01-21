class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(auto p:nums) ans=ans^p;
        return ans;
    }
};