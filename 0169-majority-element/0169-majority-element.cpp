class Solution {
public:
    int majorityElement(vector<int>& nums) {
      // using map
      int n=nums.size();
      map<int,int>map;
      for(int i=0;i<n;i++){
         map[nums[i]]++;
         if(map[nums[i]]>n/2) return nums[i];
      }
        return INT_MIN;
    }
};