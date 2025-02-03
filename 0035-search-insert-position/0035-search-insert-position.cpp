class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n=nums.size();
        int high=n-1,low=0,mid;
        while(high>=low){
            mid=low+(high-low)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]<target) low=mid+1;
            else high=mid-1;
        }
        if(nums[mid]>target)return  mid; 
        else return mid+1;
    }
};