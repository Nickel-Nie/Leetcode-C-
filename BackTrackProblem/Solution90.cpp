//
// Created by 聂伟豪 on 2023/2/9.
//
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    //子集问题：元素可重，不可复选
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        //因为存在重复元素，将重复元素放在一块更方便进行判断，所以可以进行一次排序
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> t;

        backtrack(nums, ans, t, 0);
        return ans;

    }
private:
    void backtrack(const vector<int>& nums, vector<vector<int>> &ans, vector<int> &t, int i){
        ans.emplace_back(t);

        for(int j=i; j<nums.size(); j++){
            //额外进行判断，当前元素能否加入

            //需要跳过的情况，当前值与前面的值相等 且 前面的值没有被选入t中
            //注意是j>i不是j>0，这里是以每一层的起始点而言，即从下标i开始。可以画多叉树来理解。
            //剪枝逻辑，值相同的相邻树枝，只遍历第一条
            if(j > i && nums[j] == nums[j-1]){
                continue;
            }

            t.emplace_back(nums[j]);
            backtrack(nums, ans, t, j+1);
            t.pop_back();
        }
    }
};