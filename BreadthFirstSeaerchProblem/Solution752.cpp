//
// Created by 聂伟豪 on 2023/2/9.
//
#include "string"
#include "vector"
#include "unordered_set"
#include "queue"

//还可以利用双向BFS.见: https://labuladong.github.io/algo/di-ling-zh-bfe1b/bfs-suan-f-463fd/
//不再使用队列，而是使用集合从而快速判断两个集合间是否有交集
//并且需要在while循环最后交换q1与q2的内容


using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());  //转换为hash_set从而更快发现
        unordered_set<string> seen = {"0000"};  //用hash_set存储已经看到过的内容

        int minStep = 0;
        string start = "0000";

        //两种特殊情况的返回
        if (target == "0000"){
            return 0;
        }
        if (dead.count("0000")){
            return -1;
        }

        //获取下一个数字
        auto next = [](char x) -> char {
            return x == '9' ? '0' : x+1;
        };
        //获取上一个数字
        auto prev = [](char x) -> char {
            return x == '0' ? '9' : x-1;
        };
        //当前轮盘转一次可以得到的值
        auto get = [&](string &s) -> vector<string> {
            vector<string> ans;

            for(int i=0; i<s.size(); i++){
                auto t = s[i];
                s[i] = next(t);
                ans.emplace_back(s);
                s[i] = prev(t);
                ans.emplace_back(s);
                s[i] = t;
            }

            return ans;
        };

        queue<string> q;
        q.push(start);
        while(!q.empty()){
            auto size = q.size();
            minStep++;

            for(auto i=0; i<size; i++){
                auto cur = q.front();
                q.pop();

                for(auto &&x : get(cur)){
                    if(x == target){
                        return minStep;
                    }
                    //如果当前数字出现在了deadends中或者已经见到过，则不添加进入队列中
                    if(dead.count(x) || seen.count(x)){
                        continue;
                    }
                    q.push(x);
                    seen.insert(x);
                }
            }
        }

        return -1;
    }
};