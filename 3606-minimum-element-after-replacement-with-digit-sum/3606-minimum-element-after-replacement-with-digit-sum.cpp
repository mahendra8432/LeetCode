class Solution {
public:
    int sumofdigits(int num){
        int r,sum=0;
        while(num>0){
            r=num%10;
            sum=sum+r;
            num=num/10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int n=nums.size();
        int mini=INT_MAX,tempsum;
        for(int ele:nums){
            tempsum=sumofdigits(ele);
            if(tempsum<mini) mini=tempsum;
        }
        return mini;
    }
};