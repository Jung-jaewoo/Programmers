#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void backtrack(int N, int M, vector<int>& perm, vector<bool>& used){
    if(perm.size() == M){
        for(int n : perm)
            cout << n << " ";
        cout << "\n";
        return;
    }

    for(int i=1; i<=N; i++){
        if(!used[i]){
            used[i] = true;
            perm.push_back(i);
            backtrack(N,M,perm,used);
            perm.pop_back();
            used[i] = false;
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<int> perm; // 현재 수열
    vector<bool> used(N + 1, false); // 사용 여부 표시
    backtrack(N, M, perm, used);
    return 0;
}