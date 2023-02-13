//
// Created by 聂伟豪 on 2023/2/9.
//

#include <vector>

using namespace std;


class Solution {
public:
    //子集问题：无重复，不可复选
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> t;

        backtrack(nums, ans, t, 0);
        return ans;
    }

private:
    void backtrack(const vector<int>& nums, vector<vector<int>> &ans, vector<int> &t, int i){
        ans.emplace_back(t);

        for(int j=i; j<nums.size(); j++){
            t.emplace_back(nums[j]);
            backtrack(nums, ans, t, j+1);
            t.pop_back();
        }
    }
};