#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(); // size of the given array.
    map<int, int> mpp;
    int preSum = 0, cnt = 0;

    mpp[0] = 1; // Setting 0 in the map.
    for (int i = 0; i < n; i++) {
        // add current element to prefix Sum:
        preSum += nums[i];

        // Calculate x-k:
        int remove = preSum - k;

        // Add the number of subarrays to be removed:
        cnt += mpp[remove];

        // Update the count of prefix sum
        // in the map.
        mpp[preSum]++;
    }
    return cnt;
    }
};