#include <string>
#include <vector>
#include <iostream>

using namespace std;

void positionCheck(string& name, vector<bool>& tobefixedPosition){
    int size = name.size();
    for(int i=0; i<size; i++)
        if(name[i] != 'A')
            tobefixedPosition[i] = true;
}

void positionChange(int& answer, int& currentPostion, vector<bool>& tobefixedPosition){
    int size = tobefixedPosition.size();
    int lLongest=0, rLongest=0, lShortest=0, rShortest=0;
    for(int i=0; i<=size/2; i++){
        if(tobefixedPosition[i]==true)
            rLongest = i;
    }
    for(int i=(int)(size/2)+1; i<size; i++){
        if(tobefixedPosition[i]==true){
            lLongest = i;
            break;
        }
    }
    for(int i=1; i<=size; i++){
        if(tobefixedPosition[i]==true){
            rShortest = i;      
            break;
        }
    }
    for(int i=size-1; i>=0; i--){
        if(tobefixedPosition[i]==true){
            lShortest = i;
            break;
        }
    }
    int sol1,sol2;
    (size-lLongest<rLongest)?sol1=(size-lLongest)*2+rLongest:sol1=2*rLongest+size-lLongest;
    (lShortest<size-rShortest)?sol2=lShortest:sol2=size - rShortest;
    (sol1<sol2)?answer+=sol1:answer+=sol2;
    cout << sol1 << " " << sol2;
}

void charChange(string& name, int& position, int& answer){
    int indexDiff = name[position] - 'A';
    if(indexDiff <= 13){
        answer += indexDiff;
        return;
    }
    answer+= 26-indexDiff;
}

int solution(string name) {
    int answer = 0;
    int currentPosition = 0;
    vector<bool> tobefixedPosition;
    tobefixedPosition.resize(name.size(),false);
    
    positionCheck(name,tobefixedPosition);
    positionChange(answer, currentPosition, tobefixedPosition);
    for(int i=0; i<name.size(); i++){
        if(tobefixedPosition[i])
            charChange(name,i,answer);
    }
        
    return answer;
}