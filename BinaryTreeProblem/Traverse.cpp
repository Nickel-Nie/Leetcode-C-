//
// Created by 聂伟豪 on 2023/2/9.
// 二叉树问题的分类：1. 遍历问题（回溯）；2.分解问题(通过子(树)问题推导、动态规划)
// 二叉树的遍历：前序、中序、后序、层序
//

#include "TreeNode.h"
#include "queue"
#include "list"
using namespace std;

class BinaryTreeAlgorithm{

public:

    static void traverse(TreeNode* root) {
        if(root == nullptr){
            //递归退出条件
            return;
        }

        //前序遍历处理
        traverse(root->left);
        //中序遍历处理
        traverse(root->right);
        //后续遍历处理
    }

    //层序遍历，同样也可用于图的BFS中，统计最小步数
    static void levelTraverseQueue(TreeNode *root) {
        if(root == nullptr) return;

        //层序遍历需要利用到队列
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            auto size = q.size();  //每一层的节点数量

            //依次取出当前层的所有节点，并将下层节点依次推入队列中
            for(auto i=0; i<size; i++){
                auto node = q.front();
                q.pop();

                //当前节点的处理
                //...

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }
    }

    static void levelTraverseRecur(TreeNode *root){
        if(root == nullptr) return;

        list<TreeNode*> nodes;  //记录每一层的节点指针
        nodes.push_back(root);
        levelTraverseRecur(nodes);
    }

    static int maxDepthTraverse(TreeNode* root){
        int depth;
        maxDepth(root, depth, 1);  //根节点深度为1
        return depth;
    }

    //分解法求最大深度
    static int maxDepth(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        return l > r ? l+1 : r+1;
    }

private:
    //递归法,depth传入0，传出为树的深度
    static void maxDepth(TreeNode* root, int &depth, int curDepth){
        if(root == nullptr){
            depth = depth > curDepth - 1 ? depth : curDepth - 1;
            return;
        }
        maxDepth(root->left, depth, curDepth+1);
        maxDepth(root->right, depth, curDepth+1);
    }

    static void levelTraverseRecur(list<TreeNode*> &curLevelNodes){
        if(curLevelNodes.empty()) return;

        list<TreeNode*> nextLevelNodes;  //记录下一层的节点指针
        //前序处理当前层的所有节点
        for(auto node : curLevelNodes){
            //处理逻辑..
            if(node->left) nextLevelNodes.push_back(node->left);
            if(node->right) nextLevelNodes.push_back(node->right);
        }

        //前序位置处理

        //递归下一层
        levelTraverseRecur(nextLevelNodes);

        //后续位置处理
    }
};
