class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0, mini = prices[0], maxprofit = 0;
        for (auto p : prices) {
            if (p < mini) mini = p;
            else {
                profit = p - mini;
                if (profit > maxprofit) maxprofit = profit;
            }
        }
        return maxprofit;
    }
};