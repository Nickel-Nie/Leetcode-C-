//
// Created by 聂伟豪 on 2023/2/15.
// 难想到的地方：需要逆着推

#include <vector>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        //dp[i][j]表示从grid[i][j]到右下角所需要的最小生命值。
        //dp[i][j]由dp[i+1][j]和dp[i][j+1]推出
        //如果当前点grid[i][j]为负数，说明所需生命值还需要增加，减去grid[i][j]
        //如果当前点grid[i][j]为正数，说明所需生命值可以减少，但如果减少到了负值，说明当前点回的血够后面的路程所用，因此该点所需的最小生命值为1

        dp[m-1][n-1] = (1-grid[m-1][n-1]) > 0 ? (1-grid[m-1][n-1]) : 1;

        for (int i = m-1; i >= 0; --i) {
            for (int j = n-1; j >= 0; --j) {
                if(i==m-1 && j==n-1) continue;
                else if(i==m-1){
                    dp[i][j] = dp[i][j+1] - grid[i][j];
                } else if(j==n-1) {
                    dp[i][j] = dp[i + 1][j] - grid[i][j];
                } else {
                    dp[i][j] = min(dp[i+1][j], dp[i][j+1]) - grid[i][j];
                }
                if(dp[i][j] <= 0) dp[i][j] = 1;
            }
        }

        return dp[0][0];
    }
};