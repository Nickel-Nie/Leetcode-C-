//
// Created by 聂伟豪 on 2023/2/9.

//以前没想到过的枚举算法。
//

#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        pair<int,int> res;

        for(int i=0; i<s.length(); i++){
            auto [l1, r1] = palindrome(s, i, i);
            auto [l2, r2] = palindrome(s, i, i+1);
            if(r1 - l1 > res.second - res.first){
                res.first = l1;
                res.second = r1;
            }
            if(r2 - l2 > res.second - res.first){
                res.first = l2;
                res.second = r2;
            }
        }

        return s.substr(res.first, res.second - res.first + 1);
    }

private:
    pair<int,int> palindrome(const string &s, int l, int r) {
        //以s[l]和s[r]为中心的回文串
        while(l>=0 && r<s.length() && s[l] == s[r]){
            l--;
            r++;
        }
        return {l+1, r-1};
    }
};