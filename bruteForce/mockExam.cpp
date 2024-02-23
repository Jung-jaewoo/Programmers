#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> answersArr = {{1,2,3,4,5}, {2,1,2,3,2,4,2,5}, {3,3,1,1,2,2,4,4,5,5}};
    int cnt[3]={0, 0, 0};
    
    int size = answers.size();
    for(int i=0; i<size; i++){
        for(int j=0; j<3; j++){
            if(answers[i] == answersArr[j][i%answersArr[j].size()])
                cnt[j]++;
        }
    }
    int max = 0;
    for(int i=0; i<3; i++){
        if(max<cnt[i])
            max=cnt[i];
    }
    for(int i=0; i<3; i++){
        if(max == cnt[i]){
            answer.push_back(i+1);
        }   
    }
    return answer;
}