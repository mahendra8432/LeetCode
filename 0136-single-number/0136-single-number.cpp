class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++){
            if(i%2==0 && nums[i]!=nums[i+1]) return nums[i];
        }
        return nums[nums.size()-1] ;
    }
};