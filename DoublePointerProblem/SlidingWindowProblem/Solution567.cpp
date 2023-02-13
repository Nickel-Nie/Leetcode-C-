//
// Created by 聂伟豪 on 2023/2/10.
//

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> m,tmp;
        for(auto&& c : s1){
            m[c]++;
        }
        tmp = m;

        int l=0, r=0;
        while(r < s2.size()){
            auto rc = s2[r];
            r++;

            /**
             * 这里的条件有：
             * 1. 如果rc为s1中不存在的字符，说明需要直接将窗口收缩至r处，因为包含这个字符的子串都是不满足条件的
             * 2. 如果rc为s1中的字符，但是多出来了，那么就需要收缩左边界
             */
             if(m.count(rc) == 0){
                 l = r;
                 m = tmp;
                 continue;
             }

             m[rc]--;
             while(m[rc] < 0){
                 auto lc = s2[l];
                 l++;
                 m[lc]++;
             }
             if(r-l == s1.size()){
                 return true;
             }
        }

        return false;
    }
};