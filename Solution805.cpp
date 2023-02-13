//
// Created by 聂伟豪 on 2022/11/14.
//

#include <vector>
#include <string>
#include <numeric>

using namespace std;

class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n = nums.size();
        int m = n / 2;
        int sum = accumulate(nums.begin(), nums.end(), 0);

        bool isInt = false;
        for(int i=1; i<=m; i++){
            if(i * sum % n == 0){
                isInt = true;
                break;
            }
        }
        if(!isInt){
            return false;
        }
        vector<vector<bool>> dp(m+1, vector<bool>(sum+1, false));
        dp[0][0] = true;

        for(int num : nums){
            for(int i=m; i>=1; i--){
                //针对每个数只有选与不选
                for(int j=num; j<=sum; j++){
                    dp[i][j] = dp[i-1][j-num];
                    if(dp[i][j] && i * sum == j * n){
                        return true;
                    }
                }
            }
        }

        //怎么使他恰好为k个？
        //利用set来减少第三层循环的次数。
//        vector<unordered_set<int>> dp(m + 1);
//        dp[0].insert(0);
//        for (int num: nums) {
//            在前几次循环中，dp[1]会增长，然后是dp[2]。。。逐渐到dp[m]
//            逆序的原因就是为了防止dp[1]构建完成后，dp[2]利用到了新的dp[1]中的内容。导致不是使用前i个数来进行更新。
//            for (int i = m; i >= 1; i--) {
//                for (int x: dp[i - 1]) {
//                    int curr = x + num;
//                    if (curr * n == sum * i) {
//                        return true;
//                    }
//                    dp[i].emplace(curr);
//                }
//            }
//        }


        return false;
    }
};