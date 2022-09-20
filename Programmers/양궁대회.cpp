#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int max_gap;
vector<int> ans;

int calcScore(const vector<int>& lion, const vector<int>& apeach) {
    int lion_score = 0, apeach_score = 0;
    
    for (int i=0; i<=10; i++) {
        if (lion[i] == 0 && apeach[i] == 0) continue;
        if (lion[i] > apeach[i]) lion_score += i;
        else apeach_score += i;
    }
    
    return lion_score - apeach_score;
}

void dfs(int n, vector<int> lion, const vector<int>& apeach) {
    if (lion.size() == 10) {
        lion.push_back(n);
        int gap = calcScore(lion, apeach);
        if (gap > max_gap) {
            max_gap = gap;
            ans = lion;
        }
        
        return;
    }
    
    for (int i=n; i>=0; i--) {
        lion.push_back(i);
        dfs(n-i, lion, apeach);
        lion.pop_back();
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;
    
    reverse(info.begin(), info.end());
    
    dfs(n, {}, info);
    if (max_gap == 0) return answer = {-1};
    else answer = ans;
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}
