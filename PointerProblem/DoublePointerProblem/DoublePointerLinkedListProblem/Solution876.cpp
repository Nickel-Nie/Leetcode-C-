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
    ListNode* middleNode(ListNode* head) {
        auto fast = head->next, slow = head;

        while(fast){
            fast = fast->next;
            slow = slow->next;
            if(fast) fast = fast->next;
        }
        return slow;
    }
};