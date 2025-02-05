class Solution {
public:
    int findMin(vector<int>& nums) {
        // find first index of second part and return nums[idx] i.e minimum;
         int n=nums.size();
        int low=0,high=n-1,mid;
         while(high>low){
            if(nums[low]<nums[high]) return nums[low];
            mid=low+(high-low)/2;
            if(nums[mid]>=nums[0]) low=mid+1;
            else high=mid;
        } 
        return nums[low];
    }
};