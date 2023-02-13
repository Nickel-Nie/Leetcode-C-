//
// Created by 聂伟豪 on 2023/2/9.
// 类似的题目：27.移动元素、83.删除排序链表中的重复元素
//

#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=1;
        while(j < nums.size()) {
            if(nums[i] != nums[j]){
                nums[++i] = nums[j];
                j++;
            } else {
                j++;
            }
        }
        return i+1;
    }
};