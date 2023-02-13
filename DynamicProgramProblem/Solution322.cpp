//
// Created by 聂伟豪 on 2023/2/9.
//

#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, amount+1);  //值初始化amount+1表示无法利用已有的硬币凑出amount值

        dp[0] = 0; //初始条件

        //根据最优子问题，自底向上进行递推
        for(int i=0; i<=amount; i++){
            for(auto &&coin : coins){
                if(i-coin < 0) continue;

                //说明可以利用子问题得到当前问题的最优解
                dp[i] = min(dp[i], dp[i-coin] + 1);
            }
        }

        return dp[amount] == amount+1 ? -1 : dp[amount];
    }
};