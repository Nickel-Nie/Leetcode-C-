//
// Created by 聂伟豪 on 2022/10/16.
//

#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int curMin = INT_MAX, curMax = 0;
        int n = nums.size();
        long long ans = 0;

        for (int i = 0; i < n; ++i) {
            curMin = nums[i];
            curMax = nums[i];
            for (int j = i; j < n; ++j) {
                curMax = max(curMax, nums[j]);
                curMin = min(curMin, nums[j]);

                if (curMax == maxK && curMin == minK){
                    ans++;
                }
            }
        }

        return ans;
    }
};