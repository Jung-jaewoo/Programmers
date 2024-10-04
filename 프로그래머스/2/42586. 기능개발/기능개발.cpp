#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> done;
    
    for(int i=0; i<progresses.size(); i++){
        done.push_back((100-progresses[i])/speeds[i]);
        if((100-progresses[i])%speeds[i]) done[i]+=1;
    }
        
    
    int idx = 0;
    while(1){
        if(idx >= done.size()) break;
        
        int idx_cnt = 0;
        while(idx + idx_cnt < done.size() && done[idx + idx_cnt] <= done[idx] )
            idx_cnt++;
        
        answer.push_back(idx_cnt);
        idx = idx + idx_cnt;
    }
    
    return answer;
}