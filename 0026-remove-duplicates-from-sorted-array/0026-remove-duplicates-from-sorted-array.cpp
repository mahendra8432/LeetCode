class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        unordered_map<int,int>map;
        for(int j=0;j<n;j++){
            map[nums[j]]++;
        }
        for(auto p:map){
            nums[i]=p.first;
            i++;
        }
        i--;
        sort(nums.begin(),nums.begin()+i+1);
        return map.size();
        
    }
};