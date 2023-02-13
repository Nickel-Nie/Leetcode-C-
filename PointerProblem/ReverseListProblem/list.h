//
// Created by 聂伟豪 on 2023/2/8.
//

#ifndef LEETCODE_LIST_H
#define LEETCODE_LIST_H

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#endif //LEETCODE_LIST_H
