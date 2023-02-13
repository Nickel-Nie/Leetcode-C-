//
// Created by 聂伟豪 on 2023/2/9.
//

#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0, j=0;
        while(j<nums.size()){
            if(nums[j] != 0){
                swap(nums[i], nums[j]);
                i++;
            }
            j++;
        }
    }
};