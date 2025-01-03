class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
            long long sum1=0;
        for(long long i=0;i<nums.size();i++){
            sum1=sum1+nums[i];
        }
        long long sum2=0,count=0;
         for(long long i=0;i<nums.size()-1;i++){
            sum2=sum2+nums[i];
            sum1=sum1-nums[i];
            if(sum2>=sum1) count++;
        }
        return count;
    }
};