//
// Created by 聂伟豪 on 2023/2/14.
// 二维最长子序列问题

#include <vector>

using namespace std;

class Solution {
public:
    //dp方法超时了
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const auto& a, const auto& b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });

        int n = envelopes.size();
        //dp法
//        vector<int> dp(n, 1);
//        for (int i = 0; i < n; ++i) {
//            for (int j = 0; j < i; ++j) {
//                if(envelopes[i][1] > envelopes[j][1]){
//                    dp[i] = max(dp[i], dp[j]+1);
//                }
//            }
//        }
//
//        return *max_element(dp.begin(),  dp.end());


        //二分查找法
        vector<int> tail = {envelopes[0][1]};  //tail[i]表示长度为i+1的子序列的末尾值
        for(int i=1; i<n; i++){
            int num = envelopes[i][1];

            if(num > tail.back()){
                tail.push_back(num);
            } else {
                auto it = lower_bound(tail.begin(), tail.end(), num);
                *it = num;
            }
        }
        return tail.size();
    }
};