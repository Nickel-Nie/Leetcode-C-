//
// Created by 聂伟豪 on 2023/2/9.
//

#include <vector>

using namespace std;


class Solution {
public:
    //组合问题：无重复，不可复选, 通过修改Solution78的部分代码即可。
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> t;

        backtrack(n, ans, t, 1, k);
        return ans;
    }

private:
    void backtrack(const int& n, vector<vector<int>> &ans, vector<int> &t, int i, int k){
        if(t.size() == k){  //只把数量等于k的加入集合中
            ans.emplace_back(t);
        }

        for(int j=i; j<=n; j++){
            t.emplace_back(j);
            backtrack(n, ans, t, j+1, k);
            t.pop_back();
        }
    }
};