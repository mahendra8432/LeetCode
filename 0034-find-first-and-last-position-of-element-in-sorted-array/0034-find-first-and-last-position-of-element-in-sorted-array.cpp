class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        int high=n-1,low=0,mid,p;
        bool flag=false;
        while(high>=low){
            mid=low+(high-low)/2;
            if(nums[mid]==target){
               p=mid;
                flag=true;
                break;
            }
            else if(nums[mid]>target) high=mid-1;
            else low=mid+1;
        }
       if(flag){
        while(mid>=0 && nums[p]==nums[mid]) mid--;
        int ini=mid+1;mid=p;
        while(mid<n && nums[p]==nums[mid]) mid++;
        int fin=mid-1;
        return {ini,fin};
       }
       else return {-1,-1};
    }
};