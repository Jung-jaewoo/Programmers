#include <string>
#include <vector>
#include <set>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    set<string> num_set(phone_book.begin(),phone_book.end());

    string cmp = "";
    for(auto num1 : num_set)
        for(int i=1; i<num1.size(); i++)
            if(num_set.find(num1.substr(0,i)) != num_set.end())
                return false;
     
    return answer;
}