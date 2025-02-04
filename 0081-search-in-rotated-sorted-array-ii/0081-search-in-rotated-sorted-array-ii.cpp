class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1,mid;
        while(high>=low){
            mid=low+(high-low)/2;
            if(nums[mid]==target) return true;
            if( nums[low]==nums[high] && nums[low]==nums[mid]){
                 low++;high--;continue;
            }
            if(nums[mid]>=nums[low]){// left array is sorted.
                if(nums[mid]>target && nums[low]<=target) high=mid-1;
                else low=mid+1;
            }
            else{// right array is sorted
                 if(nums[mid]<target && nums[low]>target) low=mid+1;
                 else high=mid-1;
            }
        }
        return false;
    }
};