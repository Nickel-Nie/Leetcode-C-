//
// Created by 聂伟豪 on 2023/2/9.
//

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";  //初始化

        unordered_map<char, int> m;
        for(auto&& c:t){
            m[c]++;
        }
        int targetNum = t.length();  //t中还剩多少字符没有被找到
        int minIdx = -1, minLen = s.length() + 1;

        int l=0, r=0;
        // [l,r]
        while(r < s.length()){
            auto c = s[r];
            //扩展右边界的情况：当前窗口内没有包含t中所有的字符。
            //如何快速判断? 同样影响左边界的收缩。
            //利用一个数来单独记录目标字符串中还剩多少字符没有被找到

            //说明该字符存在于目标字符串内，且不是多出来的
            if(m[c] > 0){
                targetNum--;
            }
            m[c]--;

            //说明当前窗口内已经包含了t中所有的字符，开始收缩左边界
            while(targetNum == 0){
                //拿到最左边的字符，尝试将其推出
                auto x = s[l];
                m[x]++;

                //说明若将该字符推出，则会导致窗口内字符不能包含t中的所有字符，因此为一个最小窗口
                if(m[x] > 0){
                    if(r-l+1 < minLen){
                        minIdx = l;
                        minLen = r-l+1;
                    }
                    targetNum++;
                }
                l++;
            }
            r++;
        }

        return minIdx == -1 ? "" : s.substr(minIdx, minLen);
    }
};