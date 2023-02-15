//
// Created by 聂伟豪 on 2023/2/15.
//

#include <vector>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT32_MAX));

        dp[0][0]=grid[0][0];
        for(int i=1; i<m; i++){
            dp[i][0] = dp[i-1][0] + grid[i][0];
        }
        for (int i = 1; i < n; ++i) {
            dp[0][i] = dp[0][i-1] + grid[0][i];
        }

        //应最小化损失的生命值而不是最大化血量
        //假设dp[i][j]为负时表示损失的生命值
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {

            }
        }

        return dp[m-1][n-1] >= 0 ? 0 : -dp[m-1][n-1];
    }
};