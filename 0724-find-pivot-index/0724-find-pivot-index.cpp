class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> sw1(n,0),sw2(n,0);
        sw1[0]=nums[0],sw2[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            sw1[i]=sw1[i-1] + nums[i];
            sw2[n-i-1]=sw2[n-i] + nums[n-i-1];
        }

        for(int i=0;i<n;i++){
            if(sw1[i]==sw2[i]) return i;
        }
        return -1;
    }
};