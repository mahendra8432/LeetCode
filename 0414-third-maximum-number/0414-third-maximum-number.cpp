class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int count=0;
        if(n==1||n==2) return nums[n-1];
        for(int i=n-1;i>=1;i--){
            if(nums[i]>nums[i-1]) count++;
            if(count==3) return nums[i];
        }
        if(count==2) return nums[0];
        return nums[n-1];
    }
};