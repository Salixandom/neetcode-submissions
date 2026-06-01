class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int day = 0;
        int n = prices.size();

        while(day < n - 1) {
            while(day < n - 1 && prices[day] >= prices[day + 1]) {
                day++;
            }

            int buy = prices[day];

            while(day < n - 1 && prices[day] <= prices[day + 1]) {
                day++;
            }

            int sell = prices[day];

            profit += sell - buy;
        }

        return profit;
    }
};