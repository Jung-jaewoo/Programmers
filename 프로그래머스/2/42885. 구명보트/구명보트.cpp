#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int start = 0, end = people.size()-1;
    sort(people.begin(),people.end(),greater<>());
    
    while(start<=end){
        if(people[start]+people[end]<=limit)
            end--;
        start++;
        answer++;
    }
    return answer;
}