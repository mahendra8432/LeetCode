class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> p, neg;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                p.push_back(nums[i]);
            else neg.push_back(nums[i]);
        }
        for (int i = 0; i < n/2; i++) {
            nums[2*i]=p[i];
            nums[2*i+1]=neg[i];
        }
        return nums;
    }
};