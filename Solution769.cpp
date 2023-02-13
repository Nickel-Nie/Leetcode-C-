////
//// Created by 聂伟豪 on 2022/10/13.
////
//#include <vector>
//
//using namespace std;
//
//class Solution {
//public:
//    //O(n)，单调栈
//    int maxChunksToSorted(vector<int>& arr) {
//        auto n = arr.size();
//        int stk[n];
//        int top = -1;  //栈顶下标
//
//        for (const auto &item : arr){
//            if (top < 0 || item >= stk[top]){
//                stk[++top] = item;
//            } else {
//                int maxValue = stk[top];
//                while (top >= 0 && stk[top] > item){
//                    top--;
//                }
//                stk[++top] = maxValue;
//            }
//        }
//
//        return top+1;
//    }
//
////  O(n^2)
////    int maxChunksToSorted(vector<int>& arr) {
////        auto n = arr.size();
////        int ans = 0;
////
////        int curIdx = 0, nextIdx, j;
////        int maxValue;  //已遍历区间内的最大值
////        int curMaxValue;  // 当前块的最大值
////
////        while(curIdx < n){
////            nextIdx = curIdx + 1;
////            j = nextIdx;  //arr[curIdx...nextIdx-1]为当前块
////            curMaxValue = maxValue = arr[curIdx];
////
////
////            while(j<n){  //向右拓展边界
////                if (arr[j] < curMaxValue) {
////                    nextIdx = j+1;
////                    curMaxValue = maxValue;
////                }
////                if (arr[j] > maxValue){
////                    maxValue = arr[j];
////                }
////                j++;
////            }
////            ans++;
////
////            curIdx = nextIdx;
////        }
////
////        return ans;
////    }
//
////    int maxChunksToSorted(vector<int>& arr) {
////        auto n = arr.size();
////        int ans = 0;
////        int right = 0;  //表示当前块的右边界
////
////        for (int i = 0; i < n; ++i) {
////            //对于arr[i]，它真实的位置应该在 arr[arr[i]]上。
////            if (arr[i] > right){
////                right = arr[i];
////            } else if (i == right){
////                ans++;
////                right++;
////            }
////        }
////
////        return ans;
////    }
//};
//
