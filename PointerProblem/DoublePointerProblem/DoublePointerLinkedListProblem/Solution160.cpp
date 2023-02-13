//
// Created by 聂伟豪 on 2023/2/8.
//
#include "list.h"
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto pA = headA, pB = headB;

        //走完短链
//        while(pA || pB) {
//            pA = pA->next;
//            pB = pB->next;
//
//            if(!pA && !pB) break;  //两者同时为空的情况：1. 两个链没有交集。
//            if(pA == nullptr) pA = headB;
//            if(pB == nullptr) pB = headA;
//
//            if(pA == pB){
//                return pA;
//            }
//        }

        //实际上不需要这么多判断, 把交点当做循环退出条件可修改为如下代码
        //即使两个表没有交点，退出循环后pA == pB == nullptr
        while (pA != pB){
            if(pA == nullptr) pA = headB;
            else pA = pA->next;

            if(pB == nullptr) pB = headA;
            else pB = pB->next;
        }

        return pA;
    }
};