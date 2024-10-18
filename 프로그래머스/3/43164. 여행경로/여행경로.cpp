#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool compare(vector<string> a, vector<string> b){
    if(a[0]==b[0])
        return a[1] < b[1];
    return a[0] < b[0];
}

bool dfs(int idx, vector<bool> visited, vector<vector<string>> tickets, vector<string>& route){
    if(route.size() == tickets.size() + 1){
        return true;   
    }
    string cur = tickets[idx][1];
    visited[idx] = true;
    
    for(int i=0; i<tickets.size(); i++){
        if(!visited[i] && tickets[i][0] == cur){
            route.push_back(tickets[i][1]);
            if(dfs(i,visited,tickets,route)) return true;
            route.pop_back();
        }    
    }
    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    vector<bool> visited(tickets.size(),0);
    sort(tickets.begin(),tickets.end(),compare);
    
    answer.push_back("ICN");
    for(int i=0; i<tickets.size(); i++){
        if(tickets[i][0] == "ICN"){
            answer.push_back(tickets[i][1]);
            if(dfs(i,visited,tickets,answer))
                break;
            answer.pop_back();
        }
    }
    return answer;
}