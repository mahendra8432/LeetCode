class Solution {
public:
// Method 2:- Tabulation
    int rob(vector<int>& nums) {
        int n=nums.size();
        int pick,notpick;
        vector<int>dp(n,0);
        if(n==0) return nums[0];
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            if(i>1)pick=dp[i-2] + nums[i];
            else pick=nums[i];
            notpick=dp[i-1];
            dp[i]=max(pick,notpick);
        }
        return dp[n-1];
    }
};