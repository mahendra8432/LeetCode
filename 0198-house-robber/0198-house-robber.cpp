class Solution {
public:
    int fun(int n,vector<int>&dp,vector<int>&nums){
        int left,right=INT_MIN;
        if(n==0) return nums[0];
        if(n==1) return max(nums[0],nums[1]);
        if(dp[n]!=-1) return dp[n];
        left= fun(n-2,dp,nums) + nums[n];
        right= (n>2)? fun(n-3,dp,nums):0 ;
        right  =right + max(nums[n],nums[n-1]);
        return dp[n]=max(left,right);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return fun(n-1,dp,nums);
    }
};