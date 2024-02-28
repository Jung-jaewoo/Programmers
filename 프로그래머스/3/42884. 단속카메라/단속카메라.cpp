#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 0;
    sort(routes.begin(),routes.end());
    vector<pair<int,int>> cameraRanges;
    for(int i=0; i<routes.size(); i++){
        cout << routes[i][0] << " " << routes[i][1] << "\n";
        bool flag = true;
        for(int j=0; j<cameraRanges.size(); j++){
            if(!(routes[i][0]<cameraRanges[j].first && routes[i][1]<cameraRanges[j].first) && !(routes[i][0]>cameraRanges[j].second && routes[i][1]>cameraRanges[j].second) ){
                cameraRanges[j].first = max(routes[i][0],cameraRanges[j].first);
                cameraRanges[j].second = min(routes[i][1],cameraRanges[j].second);
                flag = false;
                break;
            }
        }
        if(flag)
            cameraRanges.push_back(make_pair(routes[i][0],routes[i][1]));
    }
    answer = cameraRanges.size();
    return answer;
}