//
// Created by 聂伟豪 on 2023/2/10.
//

#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
//    int rob(TreeNode* root) {
//        if(root == nullptr) return 0;
//
//        if(memo.count(root)){
//            return memo[root];
//        }
//        //考虑抢不抢这个根节点
//        int a = root->val
//                + (root->left == nullptr ? 0 : rob(root->left->left) + rob(root->left->right))
//                + (root->right == nullptr ? 0 : rob(root->right->left) + rob(root->right->right));
//        int b = rob(root->left) + rob(root->right);
//
//        memo[root] = max(a,b);
//        return memo[root];
//    }

//优化空间复杂度，不用备忘录
// dp[0]表示选中根节点得到的最大值，dp[1]表示不选中当前根节点得到的最大值
    int rob(TreeNode* root) {
        auto res = dp(root);
        return max(res.first, res.second);
    }

private:
    unordered_map<TreeNode*, int> memo;

    pair<int,int> dp(TreeNode *root){
        if(root == nullptr) return {0,0};

        auto left = dp(root->left);
        auto right = dp(root->right);

        int robRoot = root->val + left.second + right.second;
        int notRobRoot = max(left.first, left.second) + max(right.first, right.second);

        return {robRoot, notRobRoot};
    }
};