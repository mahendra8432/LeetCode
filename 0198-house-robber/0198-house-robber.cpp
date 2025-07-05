class Solution {
public:
    int fun(int n,vector<int>&dp,vector<int>&nums){
        int pick,notpick;
        if(n==0) return nums[0];
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        pick= fun(n-2,dp,nums) + nums[n];
        notpick  =0 + fun(n-1,dp,nums);
        return dp[n]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return fun(n-1,dp,nums);
    }
};