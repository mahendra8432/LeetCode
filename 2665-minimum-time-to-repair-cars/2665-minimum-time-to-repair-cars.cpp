class Solution {
public:
    bool valid(const vector<int>& ranks, int cars, long long val) {
        for (int i = 0; i < ranks.size(); i++) {
            long long curr = (long long)sqrt(val / ranks[i]);
            cars -= curr;
            if (cars <= 0)
                return true;
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 0;
        long long high =
            (long long)*max_element(ranks.begin(), ranks.end()) * cars * cars;
        long long ans = high;

        while (low <= high) {
            long long mid = (low + high)/2;
            if (valid(ranks, cars, mid)) {
                ans = mid;
                high = mid - 1;
            } 
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
};