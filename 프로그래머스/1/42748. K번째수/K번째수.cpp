#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    int cnt = commands.size();
    for(int i=0; i<cnt; i++){
        vector<int> newArray;
        for(int j=commands[i][0]-1; j<commands[i][1]; j++)
            newArray.push_back(array[j]);
        sort(newArray.begin(), newArray.end());
        answer.push_back(newArray[commands[i][2]-1]);
    }
    
    return answer;
}