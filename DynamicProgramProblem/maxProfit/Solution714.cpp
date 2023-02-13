//
// Created by 聂伟豪 on 2023/2/10.
//

#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,0));

        dp[0][0] = 0;
        dp[0][1] = -prices[0]-fee;
        for(int i=1; i<n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i] - fee);  //买入时额外加入一笔手续费用
        }
        return dp[n-1][0];
    }
};