// #include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#define INF 987654321

using namespace std;

int graph[101][101];
bool visited[101][101];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int shortestLength = INF;

bool isOut(int x, int y){
    if(x<0 || x> 100) return true;
    if(y<0 || y> 100) return true;
    return false;
}

void dfs(int curX, int curY, int itemX, int itemY, int cost){
    if(curX == itemX && curY == itemY){
        shortestLength = min(shortestLength, cost);
        return;
    }
    visited[curX][curY] = true;
    
    for(int i=0; i<4; i++){
        if(isOut(curX+dx[i], curY+dy[i])) continue;
        if(!visited[curX+dx[i]][curY+dy[i]] && graph[curX+dx[i]][curY+dy[i]] == 1)
            dfs(curX+dx[i],curY+dy[i],itemX,itemY, cost + 1);
    }
}
    
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {

    for(int i=0; i<rectangle.size(); i++){
        int start_x, start_y, end_x, end_y;
        start_x = rectangle[i][0] * 2;
        start_y = rectangle[i][1] * 2;
        end_x = rectangle[i][2] * 2;
        end_y = rectangle[i][3] * 2;
        
        for(int x = start_x; x<=end_x; x++){
            for(int y = start_y; y<=end_y; y++){
                if(graph[x][y] != 2)
                    graph[x][y] = 1;
                if(x != start_x && x != end_x && y!= start_y && y!= end_y)
                    graph[x][y] = 2;
            }
        }
    }
    // for(int i=0; i<101; i++){
    //     for(int j=0; j<101; j++){
    //         cout << graph[i][j];
    //     }
    //     cout << "\n";
    // }
    dfs(characterX*2, characterY*2, itemX*2, itemY*2, 0);
    return shortestLength/2;
}