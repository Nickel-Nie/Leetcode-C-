//
// Created by 聂伟豪 on 2022/10/16.
//
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<int> s;
        for (const auto &item : nums){
            s.insert(item);
            s.insert(reverse(item));
        }
        return s.size();
    }
private:
    int reverse(int num){
        int ret = 0;
        int last;
        while(num != 0){
            last = num % 10;
            ret = ret * 10 + last;
            num = num / 10;
        }
        return ret;
    }
};