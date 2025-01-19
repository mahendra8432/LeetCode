class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size(), p = 0;
        map<int, int> m;
        map<int, int> map2;
        for (int i = 0; i < n; i++) {
            if (m.find(nums[i]) != m.end())
                map2[nums[i]] = i;
            else
                m[nums[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            if (2 * nums[i] == target) {
                auto l = map2.find(nums[i]);
                if (l != map2.end())
                    return {i, l->second};
            }
            m.erase(nums[i]);
            auto q = m.find(target - nums[i]);
            if (q != m.end())
                return {i, q->second};
        }
         return {-1, -1};

    }
};
