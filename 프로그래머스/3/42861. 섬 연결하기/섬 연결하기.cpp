#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(vector<int> cost1, vector<int> cost2){
    return cost1[2] < cost2[2];
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<int> visited;
    visited.resize(n,0);
    sort(costs.begin(), costs.end(),compare);
    visited[costs[0][0]] = 1;
    visited[costs[0][1]] = 1;
    answer += costs[0][2];
    bool flag;
    while(1){
        flag = 1;
        for(int i=1; i<costs.size(); i++){
            if(visited[costs[i][0]]^visited[costs[i][1]]==1){
                visited[costs[i][0]]=1;
                visited[costs[i][1]]=1;
                answer += costs[i][2];
                flag = 0;
                break;
            }
        }
        if(flag)
            break;
    }
    return answer;
}