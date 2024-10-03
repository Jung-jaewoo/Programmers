#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<pair<int,int>> points;
int sum = 0;

bool checkPoint(int x, int y){
    for(int i=0; i<points.size(); i++){
        if(x == points[i].first || y == points[i].second)
            return false;
        if(x + y == points[i].first + points[i].second)
            return false;
        if(x - y == points[i].first - points[i].second)
            return false;
    }
    return true;
}

void putQueen(int& n, int x){
    if(n == x) {
        sum++;
        return;
    }
    
    for(int i=0; i<n; i++){
        if(checkPoint(x,i)){
            points.push_back(make_pair(x,i));
            putQueen(n, x + 1);
            points.pop_back();
        }
    }
}

int main(){
    int n;
    cin >> n;
    putQueen(n,0);
    cout << sum << "\n";
    return 0;
}