class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        // if(nums[0]!=0) return 0;
        // if(nums[n-1]!=n) return n;
        int i=0;
        while(i<n && nums[i]==i) i++;
        return i;

    }
};