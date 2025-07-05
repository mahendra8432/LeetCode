class Solution {
public:
// Method 2:- Tabulation
    int rob(vector<int>& nums) {
        int n=nums.size();
        int pick,notpick;
        vector<int>dp(n,0);
        if(n==1) return nums[0];
        dp[0]=nums[0];
        for(int i=1;i<n-1;i++){// not consider last element
            if(i>1)pick=dp[i-2] + nums[i];
            else pick=nums[i];
            notpick=dp[i-1];
            dp[i]=max(pick,notpick);
        }
        int ans1=dp[n-2];
        fill(dp.begin(), dp.end(), 0);  
        dp[1]=nums[1];
        for(int i=2;i<n;i++){ // not consider first element
            if(i>2)pick=dp[i-2] + nums[i];
            else pick=nums[i];
            notpick=dp[i-1];
            dp[i]=max(pick,notpick);
        }
        int ans2= dp[n-1];
        return max(ans1,ans2);
    }
};