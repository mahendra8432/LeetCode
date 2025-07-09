class Solution {
public:
// Space optimization.
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        int target=sum/2;
        vector<bool>curr(target+1,0),prev(target+1,0);
        prev[0]=curr[0]=1;
        if(nums[0]<=target) prev[nums[0]]=1;
        for(int i=1;i<n;i++){
            for(int j=1;j<=target;j++){
                bool nottake=prev[j];
                bool take=false;
                if(j>=nums[i]) take=prev[j-nums[i]];
                curr[j]=take || nottake;
            }
            prev=curr;
        }
        return prev[target];
    }
};