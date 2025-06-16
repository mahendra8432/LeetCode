class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i+1]<nums[i]){
                i++;
                while(i<n-1){
                    if(nums[i+1]>=nums[i] && nums[i+1]<=nums[0]) i++;
                    else return false;
                }
                if(nums[n-1]<=nums[0]) return true;
                else return false;
            }
        }
        return true;
    }
};
