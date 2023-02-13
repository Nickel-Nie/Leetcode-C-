//
// Created by 聂伟豪 on 2023/2/9.
//
#include <vector>

using namespace std;
class Solution {
public:
    //组合问题，元素可重不可复选
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> t;
        int tSum = 0;  //维护t的和，方便后续判断

        backtrack(candidates, ans, t, tSum, 0, target);

        return ans;
    }

private:
    void backtrack(vector<int>& candidates, vector<vector<int>> &ans, vector<int> &t, int &tSum, int i, const int &target){
        if(tSum == target){
            ans.emplace_back(t);
            return;
        }

        for(int j=i; j<candidates.size(); j++){
            //重复元素的判断，解析可见Solution90
            if(j > i && candidates[j] == candidates[j-1]){
                continue;
            }

            t.emplace_back(candidates[j]);
            tSum += candidates[j];

            //全是正数，因此可以继续剪枝
            if(tSum <= target){
                backtrack(candidates, ans, t, tSum, j+1, target);
            }

            tSum -= candidates[j];
            t.pop_back();

        }
    }
};