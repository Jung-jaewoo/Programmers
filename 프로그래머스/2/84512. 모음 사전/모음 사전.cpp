#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char alpha[5] = {'A','E','I','O','U'};

void make_string(vector<string>& words, string& word, int len, int depth){
    if(depth == len){
        words.push_back(word);
        return;
    }
    for(int i=0; i<5; i++){
        word.push_back(alpha[i]);
        make_string(words, word, len, depth+1);
        word.pop_back();
    }
}

int solution(string word) {
    int answer = 0;
    
    vector<string> words;
    string tmp;
    for(int i=1; i<=5; i++)
        make_string(words,tmp,i,0);
    sort(words.begin(), words.end());
    
    int cnt = 0;
    for(auto word_tmp : words){
        cnt++;
        if(word == word_tmp){
            answer = cnt;
            break;
        }
    }
        
    return answer;
}