//
// Created by 聂伟豪 on 2023/2/13.
//

#include "TreeNode.h"

#include "queue"

using namespace std;

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) return root;
        queue<Node*> q;
        q.push(root);

        while (!q.empty()){
            auto n = q.size();

            Node *node;
            for(int i=0; i<n; i++){
                node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);

                if(i == n-1){
                    node->next = nullptr;
                } else {
                    node->next = q.front();
                }
            }
        }

        return root;
    }
};

