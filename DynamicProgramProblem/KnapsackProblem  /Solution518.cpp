//
// Created by 聂伟豪 on 2023/2/14.
// 完全背包问题：零钱兑换2

#include <vector>

using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n+1, vector<int>(amount+1, 0));

        for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;  //凑0元，就是什么都不选，只有一种情况
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= amount; ++j) {
                if(j >= coins[i-1]){
                    //注意如果选这个硬币的情况，用的是dp[i][j-coins[i]]，因为是可以多次选择的，所以在同一行中
                    dp[i][j] = dp[i-1][j] + dp[i][j-coins[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][amount];
    }
};