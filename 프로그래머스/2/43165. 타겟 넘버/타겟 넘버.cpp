#include <string>
#include <vector>

using namespace std;

int dfs(vector<int>& numbers, int target, int idx, int sum){
    if(idx == numbers.size()){
        if(sum == target)
            return 1;
        return 0;
    }
    
    int ret = 0;
    ret += dfs(numbers, target, idx + 1, sum + numbers[idx]);
    ret += dfs(numbers, target, idx + 1, sum - numbers[idx]);
    return ret;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    answer += dfs(numbers, target, 0, 0);
    return answer;
}
