//
// Created by 聂伟豪 on 2022/10/26.
//

#include <vector>
#include <deque>

using namespace std;


class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = n+1;
        deque<int> q;  //单调递增的双端队列

        vector<int> preSum(n+1, 0);
        for (int i = 1; i <= n; ++i) {
            preSum[i] = preSum[i-1] + nums[i-1];
        }

        for (int i = 0; i <= n ; ++i) {
            int curSum = preSum[i];
            while(!q.empty() && curSum-preSum[q.front()] >= k){
                ans = min(ans, i-q.front());
                q.pop_front();
            }
            while(!q.empty() && preSum[q.back()] >= curSum){
                q.pop_back();
            }
            q.push_back(i);
        }
        return ans == n+1 ? -1 : ans;
    }
};

