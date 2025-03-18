class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxlen=0,left=0,bitmask=0;
        for(int i=0;i<n;i++){
            while((bitmask & nums[i])!=0){
                bitmask=bitmask ^ nums[left];
                left++;
            }
            bitmask=bitmask | nums[i];
            maxlen=max(maxlen,i-left+1);
        }
        return maxlen;
    }
};