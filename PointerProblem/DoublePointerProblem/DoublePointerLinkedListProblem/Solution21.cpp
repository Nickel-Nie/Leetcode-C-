//
// Created by 聂伟豪 on 2023/2/8.
//

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        auto dummy= new ListNode(-1);
        ListNode *p1 = list1, *p2 = list2, *p = dummy;

        while(p1 != nullptr && p2 != nullptr){
            if(p1->val < p2->val){
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }

            p = p->next;
        }

//        while (p1 != nullptr){
//            p->next = p1;
//            p1 = p1->next;
//            p = p->next;
//        }
//
//        while(p2 != nullptr){
//            p->next = p2;
//            p2 = p2->next;
//            p = p->next;
//        }

        //实际上只有一个链表有剩余的了。使用if直接连上就行
        if(p1 != nullptr){
            p->next = p1;
        } else{
            p->next = p2;
        }


        return dummy->next;
    }
};