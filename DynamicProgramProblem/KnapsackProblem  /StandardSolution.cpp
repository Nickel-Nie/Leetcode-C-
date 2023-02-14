//
// Created by 聂伟豪 on 2023/2/14.
//
#include <vector>

using namespace std;

class Solution{
public:
    int func(vector<int> wt, vector<int> val, int W){
        int n = wt.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= W; ++j) {
                if(j >= wt[i-1]){
                    //若当前容量能装下第i-1个物品，则有两种选择，不装和装，取两者的最大值
                    dp[i][j] = max(dp[i-1][j],  //不选
                                   dp[i-1][j-wt[i]] + val[i-1]);  //选
                } else {  //注意放不下的情况不能漏掉
                    dp[i][j] = dp[i-1][j];
                }
            }
        }

        return dp[n][W];
    }
};