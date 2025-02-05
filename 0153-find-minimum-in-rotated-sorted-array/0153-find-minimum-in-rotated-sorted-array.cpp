class Solution {
public:
    int findMin(vector<int>& nums) {
         int n=nums.size();
         //if(n==1) return nums[0];
         //if(n==2) return min(nums[1],nums[0]);
        int low=0,high=n-1,mid;
         while(high>low){
            mid=low+(high-low)/2;
            if(nums[mid]>=nums[0]) low=mid+1;
            else high=mid;
        }
        mid=low+(high-low)/2;
        if(mid==n-1 && nums[n-1]>nums[0]) return nums[0];
        else return nums[mid];
    }
};