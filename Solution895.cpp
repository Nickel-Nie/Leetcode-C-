//
// Created by 聂伟豪 on 2022/11/30.
//

#include <map>
#include <vector>
#include <queue>
#include <memory>

using namespace std;

struct cmp{
    bool operator()(vector<int> v1, vector<int> v2){
        //v[0] 表示元素；v[1]表示当前栈中存在多少个；v[2]表示当前下标
        if(v1[1] == v2[1]){
            return v1[2] < v2[2];  //相同次数，最后一个下标大的排前面
        } else{
            return v1[1] < v2[1];  //不同次数，出现次数多的排前面
        }
    }
};

class FreqStack {
public:
    FreqStack() {
    }

    void push(int val) {
        index++;
        //todo
        m[val]++;
        pq.push({val, m[val], index});
    }

    int pop() {
        //todo
        auto v = pq.top();
        pq.pop();
        index--;
        m[v[0]]--;
        return v[0];
    }

private:
    int index = -1;
    map<int, int> m; //存每个元素对应的下标值
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
};

