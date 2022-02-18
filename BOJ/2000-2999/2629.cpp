#include <iostream>
#include <string.h>

using namespace std;

int N, T;
int weight[30];
int cache[30][15001];

// dp(idx, gap): idx번째~마지막 구슬을 사용해서 차가 gap이 되게 두 집합을 만들 수 있는가?
int dp(int idx, int gap) {
    if (idx >= N || gap > 15000) return gap == 0;
    
    int& ret = cache[idx][gap];
    if (ret != -1) return ret;
    
    ret = 0;
    ret += dp(idx+1, gap);                      // idx번 구슬을 저울에 놓지 않음
    ret += dp(idx+1, gap + weight[idx]);        // idx번 구슬을 더 무거운 쪽에 놓음
    ret += dp(idx+1, abs(gap - weight[idx]));   // idx번 구슬을 더 가벼운 쪽에 놓음
    ret = ret > 0 ? 1 : 0;
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N;
    
    for(int i=0; i<N; i++) {
        cin >> weight[i];
    }
    
    cin >> T;
    
    int marble;
    
    for(int i=0; i<T; i++) {
        cin >> marble;
        
        if (marble > 15000) cout << "N ";
        else if (dp(0, marble)) cout << "Y ";
        else cout << "N ";
    }

    return 0;
}
