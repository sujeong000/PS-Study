#include <string>
#include <vector>
#include <string.h>
#include <iostream>

using namespace std;

const int MAX_TEMP = 3050;
const int MAX_N = 1010;
const int INF = 987654321;

int N, outsideTemp;
int A, B, T1, T2;
int cache[MAX_TEMP][MAX_N];
vector<int> onBoard;

int nextTemp(int currTemp) {
    int gap = outsideTemp - currTemp;
    
    if (gap > 0) return currTemp + 1;
    else if (gap < 0) return currTemp - 1;
    else return currTemp;
}

int dp(int currTemp, int t) {
    if (t == N) return 0;
    if (onBoard[t] && (currTemp < T1 || currTemp > T2)) return INF;
    
    int& ret = cache[currTemp+1050][t];
    if (ret != -1) return ret;
    
    ret = INF;
    // 그냥 켜놓기
    ret = min(ret, B + dp(currTemp, t+1));
    // 온도 낮추기
    ret = min(ret, A + dp(currTemp-1, t+1));
    // 온도 높이기
    ret = min(ret, A + dp(currTemp+1, t+1));
    // 끄기
    ret = min(ret, dp(nextTemp(currTemp), t+1));
    
    return ret;
}

int solution(int temperature, int t1, int t2, int a, int b, vector<int> onboard) {
    int answer = INF;
    outsideTemp = temperature;
    T1 = t1;
    T2 = t2;
    A = a;
    B = b;
    N = onboard.size();
    onBoard = onboard;
    
    memset(cache, -1, sizeof(cache));
    answer = dp(temperature, 0);
    
    return answer;
}
