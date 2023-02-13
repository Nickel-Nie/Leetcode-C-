//
// Created by 聂伟豪 on 2023/2/13.
//

#include "list.h"

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto end = head;
        for(int i=0; i<k; i++){
            if(end == nullptr) return head; //说明不足k个
            end = end->next;
        }
        //end相当于下一组的头结点
        //满足有K个节点，反转前k个节点即可
        auto newHead = reverseFrontN(head, k);
        head->next = reverseKGroup(end, k);
        return newHead;
    }
private:
    ListNode *successor = nullptr;
    //反转链表的前N个节点
    ListNode* reverseFrontN(ListNode *head, int n){
        if(n == 1){
            successor = head->next;  //记录后驱节点
            return head;
        }
        auto last = reverseFrontN(head->next, n-1);  //得到反转后的头结点
        head->next->next = head;
        head->next = successor;
        return last;
    }
};