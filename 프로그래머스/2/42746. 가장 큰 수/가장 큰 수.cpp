#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b){
    return a+b>b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector<string> numberToStrings;
    for(int i=0; i<numbers.size(); i++)
        numberToStrings.push_back(to_string(numbers[i]));
        
    sort(numberToStrings.begin(),numberToStrings.end(),cmp);
    
    if (numberToStrings.at(0) == "0")        
        return "0";
    
    for(int i=0; i<numberToStrings.size(); i++)
        answer+=numberToStrings[i];
    return answer;
}