#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    int n = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '(')
            n++;
        else{
            if(n==0) return false;
            n--;
        }
    }
    if(n!=0) return false;
    return answer;
}