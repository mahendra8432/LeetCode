class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long int prefix=1, suffix=1 ,ans = INT_MIN;
        int n = nums.size();
        for(int i=0;i<nums.size();i++){
            if(prefix==0){
                prefix=1;
            }
            if(suffix==0){
                suffix=1;
            }
            prefix = prefix*nums[i];
            suffix = suffix*nums[n-i-1];
            ans = max(ans , max(prefix , suffix));
        }
        return ans;
    }
};