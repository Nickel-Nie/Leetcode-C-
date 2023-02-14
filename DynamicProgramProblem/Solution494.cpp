//
// Created by 聂伟豪 on 2023/2/14.
// 回溯和动规的区别

#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //转换为子集划分问题，Solution416
        //sum(A) - sum(B) = target  =>  2sum(A) = target + sum(A) + sum(B)  =>  sum(A) = (target + sum(nums)) / 2
        //就变成了416题的自己划分问题，套用答案即可。
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if((target+sum) % 2 == 1 || sum < abs(target)) return 0;

        int targetA = (target + sum) / 2;
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(targetA+1, 0));

        //因为存在nums[i] == 0的情况，这种情况也是要考虑进去的
        dp[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= targetA; ++j) {
                if (j >= nums[i-1]){
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }


        return dp[n][targetA];
    }
//递归解法
//public:
//    int findTargetSumWays(vector<int>& nums, int target) {
//        int ans = 0;
//        recur(nums, target,0, 0,ans);
//        return ans;
//    }
//private:
//    void recur(const vector<int>& nums, const int& target, int curIdx, int curSum, int& count){
//        if (curIdx == nums.size()){
//            if (curSum == target) count++;
//            return;
//        }
//
//        recur(nums, target, curIdx+1, curSum-nums[curIdx], count);
//        recur(nums, target, curIdx+1, curSum+nums[curIdx], count);
//    }
};