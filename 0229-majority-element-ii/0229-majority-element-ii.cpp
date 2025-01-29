class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        map<int,int>map;
        vector<int>ans;
        for(int i=0;i<n;i++) {
            map[nums[i]]++;
            if(map[nums[i]]>n/3) {
                ans.push_back(nums[i]);
                map[nums[i]]=-2*n;
              }
              
            }
            return ans;
    }
};