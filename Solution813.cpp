//
// Created by 聂伟豪 on 2022/11/28.
//

#include <vector>

using namespace std;



class Solution {
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<double> preSum(n+1,0);
        for(int i=1; i<=n; i++){
            preSum[i] = preSum[i-1] + nums[i-1];
        }

        vector<vector<double>> dp(n+1, vector<double>(k+1));
        for(int i=1; i<=n; i++){
            dp[i][1] = preSum[i] / i;
        }

        for(int j=2; j<=k; j++){
            for(int i=j; i<=n; i++){
                for(int x = j-1; x < i; x++){
                    dp[i][j] = max(dp[i][j], dp[x][j-1] + (preSum[i] - preSum[x]) / (i-x));
                }
            }
        }
        return dp[n][k];
    }
};