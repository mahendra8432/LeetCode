class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;      
        reverse(nums.begin(),nums.end());
        reverse(nums.begin() + 0, nums.begin() + (k-1)+1);
        reverse(nums.begin() + k,nums.end());
    }
};