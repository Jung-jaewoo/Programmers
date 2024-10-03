#include <string>
#include <vector>

using namespace std;

int maxResult = 0;
bool visited[8];

void goNext(int idx, int k, vector<vector<int>>& dungeons, int depth){
    visited[idx] = true;
    for(int i = 0; i < dungeons.size(); i++){
        if(!visited[i] && k>=dungeons[i][0])
            goNext(i, k-dungeons[i][1], dungeons, depth+1);
    }
     maxResult = max(maxResult, depth);
    visited[idx] = false;
}

int solution(int k, vector<vector<int>> dungeons) {
    for(int i=0; i<dungeons.size(); i++){
        if(k>=dungeons[i][0])
            goNext(i, k-dungeons[i][1], dungeons, 1);    
    }
    return maxResult;
}