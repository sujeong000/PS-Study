#include <iostream>
#include <cstring>

using namespace std;

const int INF = 987654321;

int N;
int cost[20][20];
int cache[20][1 << 20];

// dp(idx, mask)
// :현재 일의 완료 상태가 mask일 때, idx~마지막 사람에게 일을 맡기는 최소 비용
int dp(int idx, int mask) {
    if (idx == N) return 0;
    
    int& ret = cache[idx][mask];
    if (ret != -1) return ret;
    
    ret = INF;
    for (int i=0; i<N; i++) {
        if ((mask & (1 << i)) != 0) continue;
        ret = min(ret, cost[idx][i] + dp(idx+1, mask|(1 << i)));
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            cin >> cost[i][j];
        }
    }
    
    cout << dp(0, 0);

    return 0;
}
