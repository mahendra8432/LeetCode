class Solution {
public:
    int getSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += (n % 10);
            n /= 10;
        }
        return sum;
    }

    int maximumSum(vector<int>& nums) {
        map<int, priority_queue<int>> mp;
        for (auto it : nums) {
            int sum = getSum(it);
            mp[sum].push(it);
        }

        long long maxi = -1;
        for (auto it : mp) {
            auto pq = it.second;
            if (pq.size() < 2) continue;
            int cnt = 0;
            long long sum = 0;
            while (!pq.empty() && cnt < 2) {
                sum += pq.top();
                pq.pop();
                cnt++;
            }
            maxi = max(maxi, sum);
        }
        return maxi;
    }
};