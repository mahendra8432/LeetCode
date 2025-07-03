class Solution {
public: 
    int climbStairs(int n) {
          if(n<=2) return n;
    //    return climbStairs(n-1)+climbStairs(n-2);
        int prev=1,prev2=1,curri;
        for(int i=2;i<=n;i++){
            curri=prev+prev2;
            prev2=prev;
            prev=curri;
        }
        return prev;
    }
};