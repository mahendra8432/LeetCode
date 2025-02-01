class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        if(n==1)return true;
        if(nums[i]%2==0){
            while(i<n){
                if(nums[i]%2!=0) return false;
                i+=2;
            }
            i=1;
           while(i<n){
                if(nums[i]%2==0) return false;
                i+=2;
            }
        }
        else{
             while(i<n){
                if(nums[i]%2==0) return false;
                i+=2;
            }
            i=1;
           while(i<n){
                if(nums[i]%2!=0) return false;
                i+=2;
            }
        }
        return true;
    }
};