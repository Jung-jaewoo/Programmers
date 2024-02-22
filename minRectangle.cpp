#include <iostream>
#include <string>
#include <vector>

using namespace std;

int bruteForce(vector<vector<int>>& sizes){
    pair<int,int> maxIndex = make_pair(0,0);
    int minWidth, small;
    for(int i=0; i<sizes.size(); i++){
        for(int j=0; j<2; j++){
            if(sizes[maxIndex.first][maxIndex.second]<sizes[i][j]){
                maxIndex = make_pair(i,j);
            }
            else if(sizes[maxIndex.first][maxIndex.second]==sizes[i][j]){
                if(sizes[maxIndex.first][(maxIndex.second+1)%2]<sizes[i][(j+1)%2])
                    maxIndex = make_pair(i,j);
            }    
        }
    }   
    
    minWidth = sizes[maxIndex.first][(maxIndex.second+1)%2];
    for(int i=0; i<sizes.size(); i++){
        sizes[i][0]<=sizes[i][1] ? small=sizes[i][0] : small=sizes[i][1];
        if(minWidth<small)
            minWidth = small;
    }
    return minWidth*sizes[maxIndex.first][maxIndex.second];
}

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    answer = bruteForce(sizes);
    return answer;
}