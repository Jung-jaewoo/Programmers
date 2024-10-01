#include <iostream>
#include <string>
#include <vector>

using namespace std;

void dfs(vector<int>& numbers, int size, int i, int sum, int target, int& answer){
    if(i+1<=size){
       sum+=numbers[i];
        dfs(numbers, size, i+1, sum, target, answer);
        
        sum-=numbers[i];
        
        sum-=numbers[i];
        dfs(numbers, size, i+1, sum, target, answer);
    }
    else{
        if(target == sum)
            answer++;
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    int sum = 0, size;
    size = numbers.size();
    dfs(numbers,size,0,sum,target,answer);
    return answer;
}