//
// Created by 聂伟豪 on 2023/2/10.
//

#include <vector>
using namespace std;

class Solution {
public:
//        //按照股票买卖问题的思路解析
//    int rob(vector<int>& nums) {
//        int n = nums.size();
//        vector<vector<int>> dp(n, vector<int>(2, 0));
//        dp[0][0] = 0;
//        dp[0][1] = nums[0];
//
//        for(int i=1; i<n; i++){
//            dp[i][0] = max(dp[i-1][1], dp[i-1][0]);  //没偷
//            dp[i][1] = dp[i-1][0] + nums[i];   //偷了
//        }
//        return max(dp[n-1][0], dp[n-1][1]);
//    }

// 自顶向下带备忘录
//    int rob(vector<int>& nums) {
//        int n = nums.size();
//        vector<int> memo(n, -1);
//        return dp(nums, 0, memo);
//    }

// 自底向上，dp[i]表示从下标i开始往后偷能得到的最大价格
//    int rob(vector<int>& nums) {
//        int n = nums.size();
//        vector<int> dp(n+2, 0);
//
//        for(int i=n-1; i>=0; i--){
//            dp[i] = max(dp[i+1], nums[i] + dp[i+2]);
//        }
//
//        return dp[0];
//    }

// 空间优化
    int rob(vector<int>& nums) {
        int n = nums.size();
        // 记录 dp[i+1] 和 dp[i+2]
        int dp_i_1 = 0, dp_i_2 = 0;
        // 记录 dp[i]
        int dp_i = 0;
        for (int i = n - 1; i >= 0; i--) {
            dp_i = max(dp_i_1, nums[i] + dp_i_2);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i;
    }

private:
    int dp(const vector<int>& nums, int start, vector<int> &memo) {
        if(start >= nums.size()){
            return 0;
        }
        if(memo[start] != -1){
            return memo[start];
        }
        memo[start] = max(dp(nums, start+1, memo), dp(nums, start+2, memo) + nums[start]);
        return memo[start];
    }
};