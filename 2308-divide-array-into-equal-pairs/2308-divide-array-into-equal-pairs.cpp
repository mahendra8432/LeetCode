class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n=nums.size();
        map<int,int>map;
        for(int i=0;i<n;i++){
            map[nums[i]]++;
        }
        for(auto p: map){
            if(p.second%2!=0) return false;
        }
        if(map.size()>n/2) return false;
        else return true;
    }
};