class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            minPrice = min(minPrice, price);           // best buy
            maxProfit = max(maxProfit, price - minPrice); // best sell
        }

        return maxProfit;
    }
};
