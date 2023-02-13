////
//// Created by 聂伟豪 on 2022/10/21.
////
//
//#include <stack>
//
//using namespace std;
//
//class StockSpanner {
//public:
//    StockSpanner() {
//        curIdx = 0;
//    }
//
//    int next(int price) {
//
//        while(!s.empty()){
//            if (s.top().first <= price){
//                s.pop();
//            }
//        }
//        int l = s.empty() ? 0 : s.top().second;
//        s.push({price, ++curIdx});
//        return curIdx - l;
//    }
//
//private:
//    stack<pair<int, int>> s;
//    int curIdx;
//};