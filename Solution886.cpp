//////
////// Created by 聂伟豪 on 2022/10/16.
//////
////
//#include <vector>
//#include <cstring>
//
//using namespace std;
//
//class Solution {
//public:
//    int find(int x, vector<int> &fa){
//        if(fa[x] == x){
//            return x;
//        }
//        return fa[x] = find(fa[x], fa);
//    }
//
//    void unit(int x, int y, vector<int> &fa){
//        int faX = find(x, fa);
//        int faY = find(y, fa);
//        if(faX == faY){
//            return;
//        }
//        fa[faX] = faY;
//    }
//
//    bool isConnect(int x, int y, vector<int>& fa){
//        return find(x, fa) == find(y, fa);
//    }
//
//    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
//        vector<int> fa(n+1,0);
//        for(int i = 1; i <= n; i++){
//            fa[i] = i;
//        }
//        vector<vector<int>> graph(n+1, vector<int>());
//        for (const auto &dislike : dislikes){
//            graph[dislike[0]].push_back(dislike[1]);
//            graph[dislike[1]].push_back(dislike[0]);
//        }
//
//        for (int i = 1; i <= n ; ++i) {
//            for(int j=0; j < graph[i].size(); j++){
//                unit(graph[i][0], graph[i][j], fa);
//                if(isConnect(i, graph[i][j], fa)){
//                    return false;
//                }
//            }
//        }
//        return true;
//    }
//};
//
//int main(){
//    Solution s;
//    vector<vector<int>> dislikes;
//    dislikes.push_back(vector<int>{1,2});
//    dislikes.push_back(vector<int>{1,3});
//    dislikes.push_back(vector<int>{2,3});
//    s.possibleBipartition(3, dislikes);
//}
//
////class Solution {
////public:
////    // 二分图，判断是否存在奇圈
////    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
////        //初始化无向图, 两边相连说明不能在同一个组中
////        vector<vector<int>> graph(n+1, vector<int>());
////        for (const auto &dislike : dislikes){
////            graph[dislike[0]].push_back(dislike[1]);
////            graph[dislike[1]].push_back(dislike[0]);
////        }
////
////        bool visit[n+1];
////        int distance[n+1];
////        memset(visit, false, sizeof(bool) * (n+1));
////        memset(distance, 0, sizeof(int) * (n+1));
////
////        for (int i = 1; i <= n ; ++i) {
////            if (!visit[i] && !dfs(graph, i, 0, 0, visit, distance)){
////                return false;
////            }
////        }
////
////        return true;
////    }
////    /**
////     *
////     * @param graph
////     * @param u
////     * @param prev
////     * @param length  从最初的点开始的路径长度
////     * @param visit
////     * @param distance 从初始点i到每个点dfs时计算的距离，
////     * @return
////     */
////    bool dfs(vector<vector<int>>& graph, int u, int prev, int length, bool visit[], int distance[]){
////        if (visit[u]){
////            //路径长度为奇数时说明为奇圈，返回false
//////            return length % 2 == 0;
////            return (length - distance[u]) % 2 == 0;
////        }
////
////        visit[u] = true;
////        distance[u] = length;
////        //存在(u,v)
////        for (const auto &v : graph[u]){
////            if(v == prev){
////                //不能回起点。
////                continue;
////            }
////            if(!dfs(graph, v, u, length + 1, visit, distance)){
////                return false;
////            }
////        }
////        return true;
////    }
////};