//
// Created by 聂伟豪 on 2022/10/16.
//

#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(nums[j] == -nums[i]){
                    ans = max(ans, abs(nums[i]));
                }
            }
        }
        return ans;
    }
};