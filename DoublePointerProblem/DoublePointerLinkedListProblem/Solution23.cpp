//
// Created by 聂伟豪 on 2023/2/8.
//
#include <vector>
#include <queue>

using std::vector;
using std::priority_queue;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct cmp{
    bool operator() (ListNode* a, ListNode* b) const {
        return a->val > b->val;
        // 与vector排序写法相反
        // a<b， vector升序排列， priority_queue大顶堆
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto dummy = new ListNode(-1);
        auto p = dummy;
//
//        // 思路很简单，每次循环找到数组中最小的一个节点取出（如何加速？一次排序+更新后的插入排序 or 直接利用优先队列）
//        ListNode *choicePtr = choose(lists);
//        while(choicePtr){
//            p->next = choicePtr;
//            p = p->next;
//            choicePtr = choose(lists);
//        }

        //优先队列版本，保证优先队列中没有空指针
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(const auto &node : lists){
            if(node){
                pq.push(node);
            }
        }

        while(!pq.empty()){
            auto top = pq.top();
            auto next = top->next;
            pq.pop();

            p->next = top;
            p = p->next;
            if(next){
                pq.push(next);
            }
        }

        return dummy->next;
    }
private:
    ListNode* choose(vector<ListNode*>& lists){
        //选择一个拥有最小值节点指针返回。
        ListNode *ret = nullptr;
        int minIdx = -1;
        for(int i=0; i<lists.size(); i++){
            if(lists[i] == nullptr){
                continue;
            }
            if(ret == nullptr || ret->val > lists[i]->val){
                ret = lists[i];
                minIdx = i;
            }
        }

        if(minIdx >= 0){
            lists[minIdx] = lists[minIdx]->next;
        }
        return ret;
    }
};