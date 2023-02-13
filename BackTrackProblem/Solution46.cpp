//
// Created by 聂伟豪 on 2023/2/9.
//
#include <vector>

using namespace std;
class Solution {
public:
    //排列问题，元素无重，不可复选
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> t;
        vector<bool> visit(nums.size(), false);

        backtrack(nums, ans, t, visit);
        return ans;
    }
private:
    void backtrack(const vector<int> &nums, vector<vector<int>> &ans, vector<int> &t, vector<bool> &visit){
        if(t.size() == nums.size()){
            ans.emplace_back(t);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            if(!visit[i]){
                visit[i] = true;
                t.emplace_back(nums[i]);
                backtrack(nums, ans, t, visit);
                t.pop_back();
                visit[i] = false;
            }
        }
    }
};