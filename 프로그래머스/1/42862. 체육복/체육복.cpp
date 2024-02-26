#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    sort(reserve.begin(),reserve.end());
    sort(lost.begin(),lost.end());
    
    for(int i=0; i<lost.size(); i++){
        for(int j=0; j<reserve.size(); j++){
            if(lost[i] == reserve[j]){
                reserve.erase(reserve.begin()+j);
                lost.erase(lost.begin()+i--);
                break;
            }
        }
    }
    
    answer = n - lost.size();
    for(int i=0; i<lost.size(); i++){
        for(int j=0; j<reserve.size(); j++){
            if(lost[i]-1 == reserve[j] || lost[i]+1 == reserve[j]){
                answer++;
                reserve.erase(reserve.begin()+j);
                break;
            }
        }
    }
    return answer;
}