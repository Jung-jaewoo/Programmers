#include <string>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<vector<bool>> puddles_check;

int solution(int m, int n, vector<vector<int>> puddles) {
    graph.resize(n+1);
    puddles_check.resize(n+1);
    for(int i=1; i<=n; i++){
        graph[i].resize(m+1);
        puddles_check[i].resize(m+1);
    }
    for(int i=0; i<puddles.size(); i++)
        puddles_check[puddles[i][1]][puddles[i][0]]=true;
        
    int x, y;
    graph[1][1] = 1;
    for(int sum = 3; sum<=m+n; sum++){
        for(x=1; x<=sum-1; x++){
            y = sum - x;
            if(!(1<=x && x<=m && 1<=y && y<=n) || puddles_check[y][x]) continue;
            if(x==1) graph[y][x] = graph[y-1][x];
            if(y==1) graph[y][x] = graph[y][x-1];
            else graph[y][x] = (graph[y][x-1] + graph[y-1][x]) % 1000000007;   
        }
    }
    return graph[n][m];
}