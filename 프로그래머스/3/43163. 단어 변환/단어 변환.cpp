#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#define INF 987654321

using namespace std;

bool visited[50];
bool graph[50][50];
int min_cost = INF;

void make_graph(vector<string>& words){
    for(int i=0; i<words.size(); i++){
        for(int j=i; j<words.size(); j++){
            if(i == j) continue;
            int diff = 0;
            for(int k=0; k<words[i].size(); k++){
                if(words[i][k] != words[j][k])
                    diff++;
            }
            if(diff == 1){
                graph[i][j] = true;
                graph[j][i] = true;
            }
        }
    }
}
    
int bfs(string begin, string target, vector<string>& words){
    int begin_idx = find(words.begin(),words.end(),begin) - words.begin();
    int target_idx = find(words.begin(),words.end(),target)- words.begin();
    queue<pair<int, int>> q;
    q.push(make_pair(begin_idx, 0));

    int cur = 0, cur_cost = 0; 
    while(q.size()!=0){
        cur = q.front().first;
        cur_cost = q.front().second;
        q.pop();
        
        if(cur == target_idx)
            return cur_cost;
            
        visited[cur] = true;
        
        for(int i=0; i<words.size(); i++){
            if(graph[cur][i] && !visited[i])
                q.push(make_pair(i,cur_cost+1));
        }
    }
    
    return 0;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    words.push_back(begin);
    bool flag = false;
    for(int i=0; i<words.size(); i++){
        if(words[i] == target)
            flag = true;
    }
    if(!flag) return 0;
    
    make_graph(words);
    answer = bfs(begin, target, words);
    return answer;
}