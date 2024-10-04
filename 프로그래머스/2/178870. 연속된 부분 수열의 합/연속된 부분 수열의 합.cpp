#include <string>
#include <vector>
#define INF 987654321
using namespace std;




vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    
    int solPtr1=-INF, solPtr2=INF;
    int ptr1 = 0, ptr2 = 0, sum = sequence[0];
    while(1){
        if(sum == k && solPtr2 - solPtr1 > ptr2 - ptr1){
            solPtr1 = ptr1;
            solPtr2 = ptr2;
        }
        if(sum<=k) {
            if(ptr2 == sequence.size()-1)
                break;
            ptr2++;
            sum += sequence[ptr2];
        }
        else{
            if(ptr1 == sequence.size()-1)
                break;
            sum -= sequence[ptr1];
            ptr1++;  
        } 
    }    
    answer.push_back(solPtr1);
    answer.push_back(solPtr2);
    return answer;
}