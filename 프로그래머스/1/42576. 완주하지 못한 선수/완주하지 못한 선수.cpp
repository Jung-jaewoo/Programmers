#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    
    string answer = "";
    unordered_map<string, int> name_cnt;
    for(auto name : completion)
        name_cnt[name] += 1;
    
    for(auto name : participant){
        if(name_cnt[name] == 0){
            answer = name;
            break;
        }
        name_cnt[name] -= 1;
    }
    return answer;
}