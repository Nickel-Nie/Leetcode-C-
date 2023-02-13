//
// Created by 聂伟豪 on 2022/11/10.
//

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        n = grid.size();
        m = grid[0].length();
        vector<vector<bool>> visit(n, vector<bool>(m, false));

        //1. 统计所有钥匙的数量，并找到起点
        int totalKeyNum = 0;
        int startX = 0, startY = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if(grid[i][j] >= 'a' && grid[i][j] <= 'z') {
                    totalKeyNum++;
                } else if(grid[i][j] == '@') {
                    startX = i;
                    startY = j;
                }
            }
        }

//        visit[startX][startY] = true;
//        dfs(startY, startY, -1, 9, totalKeyNum, grid, visit);


        return ans;
    }
private:
    int n, m;
    int ans = -1;
    bool keys[6] {false};
    int directionX[4] = {0,1,0,-1};
    int directionY[4] = {1,0,-1,0};

    // 不能用DFS， 因为是可以走重复路的。
//    void dfs(int curX, int curY, int curStep, int curKeyNum, const int& totalKeyNum, const vector<string>& grid, vector<vector<bool>> & visit){
//        //递归退出条件
//        if(curKeyNum == totalKeyNum){
//            if(ans == -1){
//                ans = curStep;
//            } else {
//                ans = min(curStep, ans);
//            }
//        }
//
//        curStep++;
//        int newX, newY;
//        for (int i = 0; i < 4; ++i) {
//            newX = curX + directionX[i];
//            newY = curY + directionY[i];
//            if (!isValid(newX, newY, grid, visit)){
//                continue;
//            }
//            visit[newX][newY] = true;
//            if (grid[newX][newY] >= 'a' && grid[newX][newY] <='f'){
//                keys[grid[newX][newY] - 'a'] = true;
//            }
//            dfs(newX, newY, )
//            visit[newX][newY] = false; //回溯
//
//        }
//    }

    bool isValid(int x, int y, const vector<string>& grid, const vector<vector<bool>> & visit){
        //越界
        if(x < 0 || x >= n || y < 0 || y >= m){
            return false;
        }
        //墙
        if(grid[x][y] == '#'){
            return false;
        }
        //已经访问过的地方
//        if(visit[x][y]){
//            return false;
//        }
        //碰到锁但是没有钥匙
        if(grid[x][y] >= 'A' && grid[x][y] <= 'F' && !keys[grid[x][y] - 'A']){
            return false;
        }

        /** 返回true的情况
         *  1. 没访问过的空房间
         *  2. 遇到钥匙的情况
         *  3. 遇到锁且有钥匙的情况
         */
        return true;
    }


};

