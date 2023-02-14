//
// Created by 聂伟豪 on 2023/2/14.
// 最长递增子序列问题

#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        auto n = nums.size();
        int ans = 1;
        vector<int> dp(n, 1);  //dp[i]表示以nums[i]为结尾的最长子序列长度

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[j]+1, dp[i]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }   
};