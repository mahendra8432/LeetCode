class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        int sum=nums[0],maxi=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]) {
                sum=sum+nums[i];
                maxi=max(maxi,sum);
            }
            else sum=nums[i];
        }
        return maxi;
    }
};