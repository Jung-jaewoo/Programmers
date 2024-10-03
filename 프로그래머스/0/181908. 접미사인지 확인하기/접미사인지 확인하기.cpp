#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix) {
    int answer = 1;
    int sizeA = my_string.size();
    int sizeB = is_suffix.size();
    for(int i=1; i<=is_suffix.size(); i++){
        if(my_string[sizeA - i] != is_suffix[sizeB-i]){
            answer = 0;
            break;   
        }
    }
    return answer;
}