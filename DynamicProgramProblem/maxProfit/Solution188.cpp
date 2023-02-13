//
// Created by 聂伟豪 on 2023/2/10.
// 与123题是相同类型的，123题限制了k=2，本题更加宽泛k可以为任意数值
// 需要理解dp[i][j][0]，dp[i][j][1]的概念
// dp[i][j][0]：第i天，最多进行j笔交易（恰好进行j笔交易？），且没有持有股票时的最大利润
// dp[i][j][1]：第i天，最多进行j笔交易（恰好进行j笔交易？），且持有股票时的最大利润

#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(2, 0)));

        //初始化
        //不允许交易的情况下，每一天的值都为：负无穷大
        for(int i=0; i<n; i++){
            dp[i][0][1] = INT32_MIN;
        }

        //第1天购入
        for(int _k=1; _k <= k; _k++){
            dp[0][_k][1] = -prices[0];
        }

        for(int i=1; i<n; i++) {
            for(int _k=1; _k <= k; _k++){
                dp[i][_k][0] = max(dp[i-1][_k][0], dp[i-1][_k][1] + prices[i]);
                dp[i][_k][1] = max(dp[i-1][_k][1], dp[i-1][_k-1][0] - prices[i]);
                //这里的更新应该理解为恰好进行了_k笔交易，因此返回值使用注释中的结果更容易理解
                //按照_k上升的顺序理解为恰好进行，按照_k下降的顺序理解为最多进行？

            }
        }
        return dp[n-1][k][0];  //还是应该返回dp[n-1][1...k][0]中的最大值
    }
};