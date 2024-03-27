#include <string>
#include <vector>

using namespace std;
// 2*w + 2*h - 4 = brown  (h-2) * (w-2) = yellow, w,h>=3
vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int h=3, w=0;
    while(h<brown){
        w = (brown+4-2*h)/2;
        if((h-2)*(w-2)==yellow)
            break;
        h+=1;
    }
    answer.push_back(w);
    answer.push_back(h);
    return answer;
}