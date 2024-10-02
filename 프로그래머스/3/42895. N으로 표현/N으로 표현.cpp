#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

set<int> dp[9];

int makeSequenceN(int N, int cnt){
    int n = N;
    for(int i=1; i<cnt; i++)
        n = n*10 + N;
    return n;
}

int solution(int N, int number) {
    for(int k = 1; k<=8; k++){
        dp[k].insert(makeSequenceN(N,k));
        for(int i=1; i<=k-1; i++){
            for(int a : dp[i]){
                for(int b : dp[k-i]){
                    dp[k].insert(a+b);
                    if(a-b>0)
                        dp[k].insert(a-b);
                    dp[k].insert(a*b);
                    if(a/b>0)
                        dp[k].insert(a/b);
                }
            }
        }
        
        if(dp[k].find(number)!=dp[k].end())
            return k;
    }       
    return -1;
}