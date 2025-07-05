class Solution {
public:
    // Method 3:- Space Optimization S.C=0(1)
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev2=0,prev=nums[0],curri=nums[0],pick,notpick;
        for(int i=1;i<n;i++){
            pick= prev2 + nums[i];
            notpick= prev;
            curri=max(pick,notpick);
            prev2=prev;
            prev=curri; 
        }
        return prev;
    }
};