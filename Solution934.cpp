////
//// Created by 聂伟豪 on 2022/10/25.
////
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//class Solution {
//public:
//    //bfs
//    int shortestBridge(vector<vector<int>>& grid) {
//        int i,j;
//        this->grid = grid;
//        bool findIsland = false;
//        for (i = 0; !findIsland && i < grid.size(); i++) {
//            for (j = 0; !findIsland && j < grid[0].size(); ++j) {
//                if (grid[i][j] == 1){
//                    findIsland = true;
//                    markIsland(i, j);
//                }
//            }
//        }
//
//        int result = 0;
//        while(!edges.empty()){
//            result++;
//            int num = edges.size();
//            for (int k = 0; k < num; ++k) {
//                auto edge = edges.front();
//                edges.pop();
//                for (const auto &c : direction){
//                    int newX = edge.first + c[0], newY = edge.second+c[1];
//                    if (isLegal(newX, newY) && this->grid[newX][newY] == 0){
//                        //扩展边界
//                        edges.push({newX, newY});
//                        this->grid[newX][newY] = 2;
//                    } else if(isLegal(newX, newY) && this->grid[newX][newY] == 1){
//                        return result;
//                    }
//                }
//            }
//
//        }
//        return result;
//    }
//private:
//    vector<vector<int>> grid;
//    queue<pair<int, int>> edges;
//    int direction[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
//    void markIsland(int i, int j){
//        if (!isLegal(i,j) || grid[i][j] == 2){
//            return;
//        }
//        if (grid[i][j] == 0){
//            grid[i][j] = 2;
//            edges.push({i,j});
//            return;
//        }
//        //岛屿上的点，只需要赋值为2
//        grid[i][j] = 2;
//        for (const auto &item : direction){
//            markIsland(item[0] + i, item[1]+j);
//        }
//    }
//
//    bool isLegal(int row, int col){
//        return row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size();
//    }
//};