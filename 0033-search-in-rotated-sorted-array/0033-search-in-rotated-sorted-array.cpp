class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1,mid;
        while(high>=low){
            mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>=nums[0]){// left array is sorted.
                if(nums[mid]>target && nums[0]<=target) high=mid-1;
                else low=mid+1;
            }
            else{// right array is sorted
                 if(nums[mid]<target && nums[0]>target) low=mid+1;
                 else high=mid-1;
            }
        }
        return -1;
    }
};