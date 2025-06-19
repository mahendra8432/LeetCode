class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>sum(n,0);
        int diff,mini=0,maxsum=INT_MIN;
        sum[0]=nums[0];
        for(int i=1;i<n;i++){
            sum[i]=sum[i-1]+nums[i];
        }
        for(int i=0;i<n;i++){
            diff=sum[i]-mini;
            if(diff>maxsum) maxsum=diff;
            if(sum[i]<mini) mini=sum[i];
        }
        return maxsum;
    }
};