//
// Created by 聂伟豪 on 2023/2/10.
// 买股票，最多只有一次交易机会
//

#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,0));

        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for(int i=1; i<n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], -prices[i]);  //注意只能买一次，所以后面直接跟-prices[i]
        }
        return dp[n-1][0];
    }
};