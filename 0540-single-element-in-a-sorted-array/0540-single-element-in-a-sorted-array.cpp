class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        else if(nums[n-1]!=nums[n-2]) return nums[n-1];
        int low=0,high=n-1,mid;
        while(high>=low){
            mid=low+(high-low)/2;
           if((high-low+1)%4==1){
                if(nums[mid]==nums[mid-1]) high=mid;//single elment first part me hai;
                else if(nums[mid]==nums[mid+1]) low=mid;
                else return nums[mid];
            }
            else{
                if(nums[mid]==nums[mid-1]) low=mid+1; //single elment first part me hai;
                else if(nums[mid]==nums[mid+1]) high=mid-1;
                else return nums[mid];
            }
        }
     return -1;
    }
};