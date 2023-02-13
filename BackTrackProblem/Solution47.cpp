//
// Created by 聂伟豪 on 2023/2/9.
//

#include <vector>

using namespace std;

class Solution {
public:
    //排列问题，元素可重，不可复选
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

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
//            if(!visit[i] && !search(nums, visit, i)){
//                visit[i] = true;
//                t.emplace_back(nums[i]);
//                backtrack(nums, ans, t, visit);
//                t.pop_back();
//                visit[i] = false;
//            }

            //修改版：
            if(visit[i]) continue;
            //有相同的数在前面且没被访问过，那么这个数就不能被选择
            //相当于维护了多个相同的数之间的相对顺序，只有前面相邻的数使用过，后面的数才能进行使用
            if(i>0 && nums[i] == nums[i-1] && !visit[i-1]) continue;

            visit[i] = true;
                t.emplace_back(nums[i]);
                backtrack(nums, ans, t, visit);
                t.pop_back();
                visit[i] = false;
        }
    }

//    bool search(const vector<int> &nums, const vector<bool> &visit, int end){
//        for(int i=0; i<end; i++){
//            //有相同的数在前面且没被访问过，那么这个数就不能被选择
//            if(nums[i] == nums[end] && !visit[i]){
//                return true;
//            }
//        }
//        return false;
//    }
};