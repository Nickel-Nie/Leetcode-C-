//
// Created by 聂伟豪 on 2023/2/13.
//

#include "list.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        auto last = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last;
    }
};