#include <string>
#include <vector>

using namespace std;

int solution(string my_string, string is_suffix) {
    int sizeA = my_string.size();
    int sizeB = is_suffix.size();
    if(sizeA < sizeB) return 0;
    return my_string.substr(sizeA-sizeB) == is_suffix;
}