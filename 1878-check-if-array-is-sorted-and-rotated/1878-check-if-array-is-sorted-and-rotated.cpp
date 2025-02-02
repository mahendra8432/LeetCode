class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int min=INT_MAX;
        bool flag=true;
        for(int i=0;i<n-1;i++){
            if(flag==false) if( nums[i]>nums[i+1]  || nums[i]>nums[0]) return false;
            if(flag && nums[i]>nums[i+1]) flag=false;
        }
        if(!flag && nums[n-1]>nums[0]) return false;
        return true;
    }
};