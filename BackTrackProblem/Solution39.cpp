//
// Created by 聂伟豪 on 2023/2/9.
//
#include <vector>

using namespace std;
class Solution {
public:
    //组合问题，元素无重可复选
    //感觉和322题目基本类似，但是322是求最优解，这个是求所有解
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
            t.emplace_back(candidates[j]);
            tSum += candidates[j];
            //全是正数，因此可以继续剪枝
            if(tSum <= target){
                //可复选和不可以复选的区别就在这，下一层可以继续从当前起点开始
                backtrack(candidates, ans, t, tSum, j, target);  //因为每个数可以重复使用，这里不需要使用j+1
            }
            tSum -= candidates[j];
            t.pop_back();
        }
    }
};