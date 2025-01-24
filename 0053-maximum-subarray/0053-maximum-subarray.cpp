class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int max=INT_MIN,sum=0;
       for(int i=0;i<n;i++){
        sum=sum+nums[i];
        if(sum>max) max=sum;
        if(sum<0) sum=0;
       }
       return max;
    }
};