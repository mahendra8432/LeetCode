class Solution {
public:
    // Method 3:- Space Optimization S.C=0(1)
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int prev2=0,prev=nums[0],curri=nums[0],pick,notpick;
        for(int i=1;i<n-1;i++){// remove last element
            pick= prev2 + nums[i];
            notpick= prev;
            curri=max(pick,notpick);
            prev2=prev;
            prev=curri; 
        }
        int ans1=prev;
        prev2=0,prev=nums[1],curri=nums[1];
        for(int i=2;i<n;i++){// remove first element
            pick= prev2 + nums[i];
            notpick= prev;
            curri=max(pick,notpick);
            prev2=prev;
            prev=curri; 
        }
        int ans2=prev;
        return max(ans1,ans2);
    }
};

// consider this as two subproblems 1st:- remove last ele, 2nd:- remove first ele and take max of both.
// because we cant take first and last at the same time.