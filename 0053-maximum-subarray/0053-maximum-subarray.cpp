class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN,sum=0,maxmini=INT_MIN;
        if(n==1) return nums[0];
       for(int i=0;i<n;i++){
        sum=sum+nums[i];
        if(sum<0){
                maxmini=max(maxmini,sum);
                sum=0;
        }
        if( sum!=0 || nums[i]==0)maxi=max(sum,maxi);
       }
       return max(maxi,maxmini);
    }
};