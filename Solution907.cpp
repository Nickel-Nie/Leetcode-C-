//
// Created by 聂伟豪 on 2022/10/28.
//

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    const static long long MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int>& arr) {
        long long ans = 0;
        arr.push_back(-1);
        stack<int> stk;
        stk.push(-1);

        for (int r = 0; r < arr.size(); ++r) {
            //维护的是一个单调递增的单调栈

            while (stk.size() > 1 && arr[stk.top()] >= arr[r]){
                int curIdx = stk.top();
                stk.pop();
                ans = (ans + arr[curIdx] * (r-curIdx) * (curIdx - stk.top())) % MOD;
            }
            stk.push(r);
        }
        return ans;
    }
};