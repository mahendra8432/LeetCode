#define INCL()                                                                 \
    ios_base::sync_with_stdio(0);                                              \
    cin.tie(0);                                                                \
    cout.tie(0)

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        INCL();

        int n = nums.size();
        int left = *min_element(nums.begin(), nums.end());
        int right = *max_element(nums.begin(), nums.end());
        int result = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            int housesToRob = 0;

            for (int i = 0; i < n; i++) {
                if (nums[i] <= mid) {
                    housesToRob++;
                    i++;
                }
            }

            if (housesToRob >= k) { //if we can rob housesToRob houses, check for lower values as well.
                result = mid;
                right = mid - 1;
            } else {    // if we cannot rob housesToRob houses, move to higher values.
                left = mid + 1;
            }
        }

        return result;
    }
};