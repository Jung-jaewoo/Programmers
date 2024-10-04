#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define ll long long 
using namespace std;

priority_queue<ll> pq;

int solution(vector<int> scoville, int K) {
    int number = 0;
    
    for(int i=0; i<scoville.size(); i++)
        pq.push((ll)-scoville[i]);
    
    while(-pq.top()<K){
        if(pq.size()<2) return -1;
        
        ll first = -pq.top();
        pq.pop();
        ll second = -pq.top();
        pq.pop();
        pq.push(-(first + (second * 2)));
        number++;
    }
    return number;
}