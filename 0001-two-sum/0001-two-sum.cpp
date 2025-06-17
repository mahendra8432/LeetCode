class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int>map;
        for(int i=0;i<n;i++){
            map[nums[i]]=i;
        }
        for(int i=0;i<n;i++){
            int t=target-nums[i],p;
            if(map.find(t)!=map.end()){
                 p=map[t];
                 if(i!=p) return {i,p};
            }
        }
        return {-1,-1};
    }
};