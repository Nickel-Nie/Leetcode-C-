//
// Created by 聂伟豪 on 2022/11/10.
//

#include <vector>
#include <string>
#include <queue>

using namespace std;

/**
 * 带状态的bfs，
 * 把当前状态也加入距离数组中了。
 * 基于一个前提：同一状态并且回到同一格，显然不会是最短路，因此这种走法需要排除。
 */
class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size();
        int m = grid[0].length();

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

        int mask = (1 << totalKeyNum) - 1;
        queue<tuple<int,int,int>> q;
        vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(1 << totalKeyNum, -1)));
        q.emplace(startX, startY, 0);
        dist[startX][startY][0] = 0; //起点

        while(!q.empty()){
            auto [x, y, curKeyMask] = q.front();  //多了一个带钥匙的状态
            q.pop();

            for(int i=0; i<4; i++){
                int newX = x + directionX[i];
                int newY = y + directionY[i];
                if(newX < 0 || newX >= n || newY < 0 || newY >= m || grid[newX][newY] == '#'){
                    continue;
                }

                if(grid[newX][newY] == '.' || grid[newX][newY] == '@'){
                    if(dist[newX][newY][curKeyMask] == -1){ //带着同样状态不能来到同一格子两次，否则显然不是最短路径
                        dist[newX][newY][curKeyMask] = dist[x][y][curKeyMask] + 1;
                        q.emplace(newX, newY, curKeyMask);
                    }
                } else if(islower(grid[newX][newY])){
                    int nextKeyMask = curKeyMask | keyToMask(grid[newX][newY]);  //新的带钥匙状态
                    if(dist[newX][newY][nextKeyMask] == -1){
                        dist[newX][newY][nextKeyMask] = dist[x][y][curKeyMask] + 1;
                        if(nextKeyMask == mask){
                            return dist[newX][newY][nextKeyMask];
                        }
                        q.emplace(newX, newY, nextKeyMask);
                    }
                } else {
                    //遇到锁的情况, 首先需要去判断有没有锁
                    if(curKeyMask & keyToMask(grid[newX][newY]) && dist[newX][newY][curKeyMask] == -1){
                        //有锁且有钥匙，并且没有以相同状态来过这个格子。
                        dist[newX][newY][curKeyMask] = dist[x][y][curKeyMask] + 1;
                        q.emplace(newX, newY, curKeyMask);
                    }
                }

            }

        }

        return -1;
    }
private:
    int directionX[4] = {0,1,0,-1};
    int directionY[4] = {1,0,-1,0};

    int keyToMask(char c){
        if(islower(c)){
            return 1 << (c-'a');
        } else {
            return 1 << (c-'A');
        }
    }
};