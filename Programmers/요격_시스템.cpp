#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

typedef pair<int, int> pii;

int solution(vector<vector<int>> targets) {
    int answer = 0;
    int n = targets.size();
    int currentPoint = 0;
    vector<pii> targetPairs;
    
    for (auto target: targets) {
        targetPairs.push_back({target[1], target[0]});
    }
    
    // 끝점 기준으로 오름차순
    sort(targetPairs.begin(), targetPairs.end());
    
    // 항상 끝점에서 요격
    for (auto targetPair: targetPairs) {
        // 기존 요격 포인트안에 들어오지 않음 -> 새로 요격
        if (targetPair.second >= currentPoint) {
            answer++;
            currentPoint = targetPair.first;
        }
    }
    
    return answer;
}
