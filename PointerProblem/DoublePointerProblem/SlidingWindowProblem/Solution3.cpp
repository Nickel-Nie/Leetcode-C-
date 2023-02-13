//
// Created by 聂伟豪 on 2023/2/10.
//

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int l=0, r=0;
        int ans = 0;

        while(r < s.length()){
            auto rc = s[r];
            r++;

            m[rc]++;
            //某个字符出现了多次，因此需要收缩窗口直至该字符推出
            while (m[rc] > 1){
                auto lc = s[l];
                l++;
                m[lc]--;
            }
            //此时窗口内保证只有不同的字符
            ans = max(ans, r-l);
        }

        return ans;
    }
};