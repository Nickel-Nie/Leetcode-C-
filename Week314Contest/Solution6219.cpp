//
// Created by 聂伟豪 on 2022/10/16.
//

#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for (int i = 0; i <= num; ++i) {
            if ((i + reverse(i)) == num){
                return true;
            }
        }
        return false;
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