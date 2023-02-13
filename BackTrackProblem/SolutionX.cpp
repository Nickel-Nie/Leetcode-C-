//
// Created by 聂伟豪 on 2023/2/9.
//

//
// Created by 聂伟豪 on 2023/2/9.
//
#include <vector>

using namespace std;
class Solution {
public:
    //排列问题，元素无重，可复选，直接不需要visit数组即可
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> t;

        backtrack(nums, ans, t);
        return ans;
    }
private:
    void backtrack(const vector<int> &nums, vector<vector<int>> &ans, vector<int> &t){
        if(t.size() == nums.size()){
            ans.emplace_back(t);
            return;
        }

        for(int i=0; i<nums.size(); i++){
            t.emplace_back(nums[i]);
            backtrack(nums, ans, t);
            t.pop_back();
        }
    }
};