//
// Created by 聂伟豪 on 2023/2/10.
//

#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        return max(robRange(nums, 0, n-2), robRange(nums, 1, n-1));
    }
private:
    int robRange(vector<int>& nums, int left, int right) {
        int n = nums.size();
        // 记录 dp[i+1] 和 dp[i+2]
        int dp_i_1 = 0, dp_i_2 = 0;
        // 记录 dp[i]
        int dp_i = 0;
        for (int i = right; i >= left; i--) {
            dp_i = max(dp_i_1, nums[i] + dp_i_2);
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        return dp_i;
    }
};