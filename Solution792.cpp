//
// Created by 聂伟豪 on 2022/11/17.
//

#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        for (int i = 0; i < s.length(); ++i) {
            if (m.find(s[i]) == m.end()){
                m[s[i]] = vector<int>{i};
            } else {
                m[s[i]].push_back(i);
            }
        }

        int ans = 0;
        int countFlag = true;
        int pIdx = -1, cIdx;
        for(const auto &w : words){
            pIdx = -1;
            countFlag = true;
            for(int i=0; i<w.length(); i++){
                cIdx = biSearch(m[w[i]], pIdx);
                if(cIdx == -1) {
                    countFlag = false;
                    break;
                }
                pIdx = m[w[i]][cIdx];
            }
            if (countFlag){
                ans++;
            }
        }
        return ans;
    }

private:
    map<char, vector<int>> m;  //预处理s，每个字符的下标列表，

    //找到第一个比val大的数
    int biSearch(const vector<int>& v, const int& val){
        int l = 0, r = v.size()-1;
        int m = 0;
        while(l <= r){
            m = (l + r)  >> 1;
            if(v[m] <= val){
                l = m+1;
            } else {
                r = m-1;
            }
        }
        return l == v.size() ? -1 : l;
    }

};
