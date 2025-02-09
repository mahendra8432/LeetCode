class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long badpairs=0;
        int n=nums.size();
        unordered_map<int,int>map;
        for(int i=0;i<n;i++){
            nums[i]=i-nums[i];
            map[nums[i]]++;
            if(map[nums[i]]==1) badpairs=badpairs + i;
            else badpairs=badpairs + i - map[nums[i]] + 1;
        }
        return badpairs;
    }
};