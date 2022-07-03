#include <iostream>
#include <cstring>

using namespace std;

int N;
int sell[16][16];
int cache[16][10][1 << 16];

// dp(curr, price, mask)
// 현재 curr이 price원에 그림을 가지고 있고
// 지금까지 그림을 산 사람들이 mask일 때,
// 더 그림을 소유할 수 있는 사람 수의 최대값
int dp(int curr, int price, int mask) {
    int& ret = cache[curr][price][mask];
    if (ret != -1) return ret;
    
    ret = 1;
    for (int next=1; next<=N; next++) {
        if (curr == next) continue;
        if ((mask & (1 << next)) != 0) continue;
        if (sell[curr][next] < price) continue;
        
        ret = max(ret, 1 + dp(next, sell[curr][next], mask|(1 << next)));
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N;
    for (int i=1; i<=N; i++) {
        string temp;
        cin >> temp;
        for (int j=1; j<=N; j++) {
            sell[i][j] = temp[j-1] - '0';
        }
    }
    
    cout << dp(1, 0, 1 << 1);

    return 0;
}
