class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Solution 1: Time O(n), Space: O(1)
        // int minSoFar = prices[0];
        // int profit = 0;

        // for(int i = 1; i < prices.size(); i++) {
        //     profit = max(profit, prices[i] - minSoFar);
        //     minSoFar = min(minSoFar, prices[i]);
        // }
        // return profit;

        // Solution 2: Time O(n), Space: O(1)
        // Can use 2 pointers
        // left = buy, right = sell
        int l = 0, r = 1;
        int profit = 0;
        while(r < prices.size()) {
            if(prices[l] < prices[r]) {
                profit = max(profit, (prices[r] - prices[l]));
            }
            else {
                l = r;
            }
            r++;
        }
        return profit;

    }
};