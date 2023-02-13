//
// Created by 聂伟豪 on 2023/2/8.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //因为要删除掉倒数第N个节点，因此需要找到倒数第N+1个节点
        //考虑到可能删除第一个节点，因此可以添加一个dummy头
        auto dummy = new ListNode(-1, head);
        auto p = dummy, q = dummy;

        //往后走n+1步
        for(int i=0; i<n+1; i++){
            q = q->next;
        }
        while(q){
            q=q->next;
            p=p->next;
        }
        p->next = p->next->next;  //跳过倒数第N个节点
        return dummy->next;
    }
};