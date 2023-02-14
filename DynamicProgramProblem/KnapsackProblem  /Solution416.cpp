//
// Created by 聂伟豪 on 2023/2/14.
// 0-1背包问题的一个变形

#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        auto sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 == 1){
            return false;
        }
        int target = sum / 2;
        int n = nums.size();
        //dp[i][j]表示从nums[0...i-1]能够找到一个和为j的子集
        vector<vector<bool>> dp(n+1, vector<bool>(target+1, false));
        //和为0，均初始化为true
        for(int i=0; i<=n; i++){
            dp[i][0] = true;
        }

        for(int i=1; i<=n; i++){
            for(int j=1; j<=target; j++){
                if(j>=nums[i-1]){
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                } else {
                    //不选
                    dp[i][j] = dp[i-1][j];
                }
            }
            if(dp[i][target]) return true;  //说明已经能够找到和为target的子数组了。
        }

        return false;
    }
};