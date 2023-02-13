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
    ListNode* partition(ListNode* head, int x) {
        //思路：两个指针，p1指向>=x的节点，p2指向<x的节点
        //初始化：p1指向第一个>=x的节点，p2为p1后面第一个<x的节点
//        ListNode *p1, *p2;
//
//        //p1的初始化
//        p1 = head;
//        while(p1 && p1->val < x) {
//            p1 = p1->next;
//        }
//        if(p1 == nullptr){
//            return head;  //没有>=x的节点
//        }
//
//        //p2的初始化
//        p2 = p1->next;
//        while(p2 && p2->val >= x){
//            p2 = p2->next;
//        }
//        if(p2 == nullptr){
//            return head;  //没有<x的节点
//        }

        //交换两个节点，设计链表节点的交换会比较麻烦。
        //因此可以想到另外一种方法，把小于x和大于等于x的的结点分别取出来构成两个独立的链表，进行拼接即可。
        using l = ListNode *;
        l head1 = new ListNode(-1), head2 = new ListNode(-1), p1 = head1, p2 = head2, p = head;
        while(p){
            if(p->val < x){
                p1->next = p;
                p1 = p1->next;
            } else {
                p2->next = p;
                p2 = p2->next;
            }
            p = p->next;
        }

        p2->next = nullptr;  //断尾
        p1->next = head2->next;  //拼接操作
        return head1->next;
    }
};