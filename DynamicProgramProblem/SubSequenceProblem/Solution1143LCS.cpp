//
// Created by 聂伟豪 on 2023/2/14.
// 最长公共子序列问题

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size(), m = text2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));  //与编辑距离的初始化类似,长度+1

        for(int i=0; i<=n; i++){
            dp[i][0] = 0;
        }
        for (int i = 0; i <= m; ++i) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if(text1[i-1] == text2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[j-1][i]);
                }
            }
        }
        return dp[m][n];
    }
};