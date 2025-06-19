class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int diff,mini=prices[0],maxProfit=INT_MIN;
        for(int i=0;i<n;i++){
            diff=prices[i]-mini;
            if(diff>maxProfit) maxProfit=diff;
            if(prices[i]<mini) mini=prices[i];
        }
        return maxProfit;
    }
};