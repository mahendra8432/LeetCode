class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = 0;
        int n = nums.size();
        while (j < n) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
            j++;
        }
        // while (i < n) {
        //     nums[i] = 0;
        //     i++;
        // }
        return i;
    }
};