#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

struct Assignment {
    string title;
    int startTime;
    int playTime;
};

int toInt(char c) {
    return c - '0';
}

int timeToInt(string t) {
    return (toInt(t[0]) * 10 + toInt(t[1])) * 60 + (toInt(t[3]) * 10 + toInt(t[4]));
}

bool cmp(const Assignment& lhs, const Assignment& rhs) {
    return lhs.startTime < rhs.startTime;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    int n = plans.size();
    vector<Assignment> assignments;
    
    for (auto plan: plans) {
        string title = plan[0];
        int startTime = timeToInt(plan[1]);
        int playTime = stoi(plan[2]);
        
        assignments.push_back({title, startTime, playTime});
    }
    
    // 시작 시간 기준 오름차순 정렬
    sort(assignments.begin(), assignments.end(), cmp);
    
    stack<Assignment> paused;
    Assignment curr = assignments[0];
    
    for (int i=1; i<n; i++) {
        Assignment next = assignments[i];
        int term = next.startTime - (curr.startTime + curr.playTime);
        
        // 다음 과제까지 텀이 있는 경우
        if (term >= 0) {
            // 현재 과제 끝내기
            answer.push_back(curr.title);
            
            // 남은 시간(텀)동안 중단했던 과제들 재개하기
            while (term > 0 && !paused.empty()) {
                int resumeTime = min(paused.top().playTime, term);
                paused.top().playTime -= resumeTime;
                term -= resumeTime;
                
                // 중단했던 과제 완료
                if (paused.top().playTime <= 0) {
                    answer.push_back(paused.top().title);
                    paused.pop();   
                }
            }
        }
        // 텀이 없는 경우
        else {
            // 현재 과제 중단
            curr.playTime -= (next.startTime - curr.startTime);
            paused.push(curr);
        }
        
        // 다음 과제 시작
        curr = next;
    }
    
    // 현재 과제 끝내기
    answer.push_back(curr.title);
    
    // 중단된 과제들 다 해결하기
    while (!paused.empty()) {
        answer.push_back(paused.top().title);
        paused.pop();
    }
    
    return answer;
}
