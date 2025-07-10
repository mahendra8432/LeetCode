class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<int> left(nums.begin(), nums.begin() + n);
        vector<int> right(nums.begin() + n, nums.end());
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        
        // generate all subset sums grouped by size.
        auto getSubsets = [&](vector<int>& arr) {
            int m = arr.size();
            vector<vector<int>> res(m + 1);
            for (int mask = 0; mask < (1 << m); ++mask) {
                int sum = 0, bits = 0;
                for (int i = 0; i < m; ++i) {
                    if (mask & (1 << i)) {
                        sum += arr[i];
                        bits++;
                    }
                }
                res[bits].push_back(sum);
            }
            return res;
        };

        vector<vector<int>> leftSums = getSubsets(left);
        vector<vector<int>> rightSums = getSubsets(right);

        for (int i = 0; i <= n; ++i) {
            sort(rightSums[i].begin(), rightSums[i].end());
        }

        int minDiff = INT_MAX;

        for (int i = 0; i <= n; ++i) {
            for (int a : leftSums[i]) {
                int leftCount = i;
                int rightCount = n - i;
                int target = totalSum / 2 - a;
                auto& vec = rightSums[rightCount];

                // binary search in right half;
                auto it = lower_bound(vec.begin(), vec.end(), target);
                
                if (it != vec.end()) {
                    int b = *it;
                    int sum1 = a + b;
                    int sum2 = totalSum - sum1;
                    minDiff = min(minDiff, abs(sum1 - sum2));
                }
                if (it != vec.begin()) {
                    --it;
                    int b = *it;
                    int sum1 = a + b;
                    int sum2 = totalSum - sum1;
                    minDiff = min(minDiff, abs(sum1 - sum2));
                }
            }
        }

        return minDiff;
    }
};
