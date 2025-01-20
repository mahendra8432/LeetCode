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
        int j = 0, k = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                nums[i] = p[j];
                j++;
            } else {
                nums[i] = neg[k];
                k++;
            }
        }
        return nums;
    }
};