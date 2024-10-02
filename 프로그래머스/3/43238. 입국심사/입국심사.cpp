#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    long long max = times.back() * (n/times.size());
    long long min = 0;
    long long mid;
    
    long long canNum;
    while(min<=max){
        // cout << min << ", " << mid << ", " << max << ":: ";
        if(min == max) break;
        mid = (max + min) / 2;
        
        canNum = 0;
        for(int i=0; i<times.size(); i++)
            canNum += mid / times[i];
        
        if(canNum<n) min = mid + 1;
        if(canNum>=n) max = mid;
    }
    answer = min;
    return answer;
}