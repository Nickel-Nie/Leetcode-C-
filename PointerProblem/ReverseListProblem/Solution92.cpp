//
// Created by 聂伟豪 on 2023/2/13.
//

//
// Created by 聂伟豪 on 2023/2/13.
//

#include "list.h"
#include <iostream>
using namespace std;

class Solution {
public:
    ListNode *successor = nullptr;
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == 1){
            return reverseFrontN(head, right);
        }
        head->next = reverseBetween(head->next, left-1, right-1);
        return head;
    }
private:
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

//有点不够优雅
//public:
//    ListNode* reverseBetween(ListNode* head, int left, int right) {
//        int cur = 1;
//        ListNode *p = head, *q = new ListNode(-1, head), *h = q;
//        while(cur < left){
//            q = p;
//            p = p->next;
//            cur++;
//        }
//        auto ret = reverseFront(cur, right, p);
//        q->next = ret.first;
//        return h->next;
//    }
//private:
//    //返回值，翻转后[left,right]中的第一个节点和最后一个节点
//    pair<ListNode*, ListNode*> reverseFront(int cur, int right, ListNode *head){
//        if(cur == right){
//            return {head, head};
//        }
//        auto ret = reverseFront(cur+1, right, head->next);
//        head->next = ret.second->next;  //后驱节点，即第right+1个节点
//        head->next->next = head;
//        return {ret.first, head};
//    }
};