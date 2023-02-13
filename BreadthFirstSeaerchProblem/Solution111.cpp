//
// Created by 聂伟豪 on 2023/2/9.
//
#include "../BinaryTreeProblem/TreeNode.h"
#include "queue"
using namespace std;

class Solution {
public:
    //二叉树的层序遍历，也可以认为是一种BFS
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;

        queue<TreeNode *> q;
        int ans = 0;

        q.push(root);
        while(!q.empty()){
            ans++;

            auto size = q.size();
            for(auto i=0; i<size; i++){
                auto node = q.front();
                q.pop();

                //该层存在叶子节点
                if(!node->left && !node->right){
                    return ans;
                }

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        return ans;
    }
};