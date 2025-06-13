class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN,idx=n;
        if(n==1) return true;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]<nums[i]) {
                maxi=nums[0];
                idx=i+1;
                if(nums[idx]>maxi) return false;
                break;
            }
        }
        for(int i=idx;i<n-1;i++){
            if(nums[i+1]<nums[i] || nums[i+1]>maxi) return false;
        }
        return true;
    }
};