#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> stk;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '('){
            stk.push('(');
        }
        else{
            if(stk.size()==0)
                return false;
            stk.pop();
        }
    }
    if(stk.size()!=0)
        return false;
    return answer;
}