#include <vector>
#include <iostream>
#include <stack>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> stk;
    
    stk.push_back(arr[0]);
    for(int i=1; i<arr.size(); i++){
        if(stk.back() != arr[i])
            stk.push_back(arr[i]);
    }

    return stk;
}