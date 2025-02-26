class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int sum=0;
        int ans=0;
        //Kadanes Algorithm
        for(int i=0;i<nums.size();i++){
            sum=max(nums[i],sum+nums[i]);
            ans=max(ans,sum);
        }
        sum=0; //to apply Kadanes Algorithm again
        for(int i=0;i<nums.size();i++){
            nums[i]*=(-1); //flipping each element
            sum=max(nums[i],sum+nums[i]);
            ans=max(ans,sum);
        }
        return ans;
    }
};