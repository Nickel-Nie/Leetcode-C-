//
// Created by 聂伟豪 on 2023/2/10.
//

#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> window, need;
        for(auto&& c: p){
            need[c]++;
        }

        vector<int> ans;
        int l=0, r=0;
        int valid=0;
        while(r < s.length()){
            auto rc = s[r];
            r++;

            //窗口扩展处理逻辑
            if(need.count(rc)){
                window[rc]++;
                if(window[rc] == need[rc]){
                    valid++;
                }
            }

            //窗口收缩处理逻辑
            if(r - l >= p.size()){
                if(valid == need.size()){
                    ans.emplace_back(l);
                }
                auto lc = s[l];
                l++;
                if(need.count(lc)){
                    //先减valid再减window
                    if(window[lc] == need[lc]){
                        valid--;
                    }
                    window[lc]--;

                }

            }

        }
        return ans;
    }
};