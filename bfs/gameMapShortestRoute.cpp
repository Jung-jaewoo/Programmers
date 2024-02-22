#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> visited;
queue<pair<int,int>> que;

void bfs(vector<vector<int>> maps, int n, int m)
{
    int x=0, y=0;
    visited[0][0] = 1;
    que.push(make_pair(x,y));
    while(que.size()!=0){
        x = que.front().first;
        y = que.front().second;
        que.pop();
        if(y-1>=0 && maps[x][y-1]==1 && visited[x][y-1]==0){
            que.push(make_pair(x,y-1));
            visited[x][y-1] = visited[x][y] + 1;
        }
        if(y+1<=m-1 && maps[x][y+1]==1 && visited[x][y+1]==0){
            que.push(make_pair(x,y+1));
            visited[x][y+1] = visited[x][y] + 1;
        }
        if(x-1>=0 && maps[x-1][y]==1 && visited[x-1][y]==0){
            que.push(make_pair(x-1,y));
            visited[x-1][y] = visited[x][y] + 1;
        }
        if(x+1<=n-1 && maps[x+1][y]==1 && visited[x+1][y]==0){
            que.push(make_pair(x+1,y));    
            visited[x+1][y] = visited[x][y] + 1;
        }
    }
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    
    visited.resize(n,vector<int>(m,0));
    bfs(maps,n,m);
    visited[n-1][m-1]==0 ? answer = -1 : answer = visited[n-1][m-1];
    return answer;
}