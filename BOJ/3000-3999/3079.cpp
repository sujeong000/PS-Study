#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
const int MAX_N = 100'001;

int N, M;
ll T[MAX_N];

// dicision(t): t초 안에 심사를 마칠 수 있는가?
bool decision(ll t) {
    ll cnt = 0;
    
    // 각 심사대별로 t초동안 처리할 수 있는 사람 수 구하기
    for (int i=0; i<N; i++) {
        cnt += t / T[i];
        if (cnt >= M) break;
    }
    
    return cnt >= M;
}

// optimize(): 입국 심사를 마치는데 걸리는 시간을 최소화
ll optimize() {
    ll lo = 0, hi = T[0] * M;
    
    // 파라매트릭 서치
    while (lo+1 < hi) {
        ll mid = (lo+hi)/2;
        if (decision(mid)) hi = mid;
        else lo = mid;
    }
    
    return hi;
}

int main() {
    cin >> N >> M;
    for (int i=0; i<N; i++) cin >> T[i];
    sort(T, T+N);
    
    cout << optimize();
    
    return 0;
}
