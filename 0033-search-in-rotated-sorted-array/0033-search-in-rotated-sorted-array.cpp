class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1,mid;
        while(high>low){
            mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>=nums[0]) low=mid+1;
            else high=mid;
        }
        mid=low+(high-low)/2;
        if(nums[mid]==target) return mid;
        if(low==n-1 && high==n-1){low=0;high=n-1;}
        
        else if(target<=nums[n-1]){
            low=mid;
            high=n-1;
        }
        else {
            low=0;
            high=mid-1;
        }
        while(high>=low){
            mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
        return -1;
    }
};