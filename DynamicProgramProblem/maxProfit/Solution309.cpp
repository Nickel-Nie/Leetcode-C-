//
// Created by 聂伟豪 on 2023/2/10.
//

/**
 * <url>https://labuladong.github.io/algo/di-ling-zh-bfe1b/yi-ge-fang-3b01b/</url>
 * 原文中的i-2不是很认可。
 * 本题解中以题解来进行解释：第i天股市结束后的状态如下
 * dp[i][0]：不持有股票，且不处于冷冻期的最大收益
 * dp[i][1]：持有股票的最大收益
 * dp[i][2]: 不持有股票，处于冷冻期的最大收益
 */

#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        auto dp = new int[n][3];
//        vector<vector<int>> dp(n, vector<int>(3, 0));

        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        dp[0][2] = 0;

        for(int i=1; i<n; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][2]);  //昨天本来就不处于冷冻期or昨天出冷冻期
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
            dp[i][2] = dp[i-1][1] + prices[i]; //处于冷冻期就表示今天卖了股票
        }
        return max(dp[n-1][0], dp[n-1][2]);
    }
};