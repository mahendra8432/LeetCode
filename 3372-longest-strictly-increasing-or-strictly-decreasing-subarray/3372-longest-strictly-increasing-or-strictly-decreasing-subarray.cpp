class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        if(nums.size()==1) return 1;
        int count=1,count2=1,maxi=INT_MIN,maxi2=INT_MIN;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]>nums[i]){
                 count++;
                 maxi2=max(maxi2,count2);
                 count2=1;
            }
            else {
                maxi=max(maxi,count);
                count=1;
                if(nums[i+1]<nums[i]) count2++;
                else {
                    maxi2=max(maxi2,count2);
                     count2=1;
                    }
            }
        }
        maxi=max(maxi,count);
         maxi2=max(maxi2,count2);
        return max(maxi,maxi2);
    }
};