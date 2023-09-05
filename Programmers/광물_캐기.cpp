#include <string>
#include <vector>
#include <string.h>
#include <iostream>

using namespace std;

const int MAX_PICK = 6;
const int MAX_MINERALS = 51;
const int DIA = 0, IRON = 1, STONE = 2;
const int INF = 987654321;

int cache[MAX_PICK][MAX_PICK][MAX_PICK][MAX_MINERALS];
int cost[3][3] = {
    {1, 1, 1},
    {5, 1, 1},
    {25, 5, 1}
};

int mineralNumber(string mineral) {
    if (mineral == "diamond") return DIA;
    else if (mineral == "iron") return IRON;
    else return STONE;
}

// 곡괭이를 각각 picks[0], picks[1], picks[2]개 가지고 있고, [idx...]번 광물들이 남았을 때 최소 피로도
int dp(vector<int> picks, int idx, vector<string>& minerals) {
    if (picks[DIA] == 0 && picks[IRON] == 0 && picks[STONE] == 0) return 0;
    if (idx == minerals.size()) return 0;
    
    int& ret = cache[picks[DIA]][picks[IRON]][picks[STONE]][idx];
    if (ret != -1) return ret;
    
    ret = INF;
    
    // pickIdx번 곡괭이를 사용
    for (int pickIdx = 0; pickIdx < 3; pickIdx++) {
        if (picks[pickIdx] == 0) continue;
        
        int costSum = 0;
        int n = min(5, (int)minerals.size() - idx);
        
        // 사용할 수 없을 때까지 사용
        for (int i=0; i<n; i++) {
            costSum += cost[pickIdx][mineralNumber(minerals[idx+i])];
        }
        
        picks[pickIdx]--;
        costSum += dp(picks, idx+n, minerals);
        picks[pickIdx]++;
        
        ret = min(ret, costSum);
    }
    
    return ret;
}

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    memset(cache, -1, sizeof(cache));
    answer = dp(picks, 0, minerals);
    
    return answer;
}
