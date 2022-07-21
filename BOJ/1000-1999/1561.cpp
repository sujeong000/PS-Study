#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll N, M;
int rides[10001];
int rideCnt[31];

// decision(k): k분 내에 모든 사람이 놀이기구에 탑승할 수 있는가?
bool decision(ll k) {
    ll childrenCnt = 0;
    
    for (int i=1; i<=30; i++) {
        childrenCnt += (k / i + 1) * rideCnt[i];
    }
    
    return childrenCnt >= N;
}

// optimize(): 모든 사람이 놀이기구에 탑승하기 위해 필요한 최소 시간
ll optimize() {
    ll lo = -1, hi = N * 30;
    
    while (lo+1 < hi) {
        ll mid = (lo+hi)/2;
        if (decision(mid)) hi = mid;
        else lo = mid;
    }
    
    return hi;
}

int findLastRide() {
    if (N <= M) return N;
    
    ll totalTime = optimize();
    
    // t = 0~(totalTime-1)일 때 사람 태우기
    for (int i=1; i<=M; i++) {
        N -= (totalTime-1) / rides[i] + 1;
    }
    
    // t = totalTime일 때 사람 태우기
    for (int i=1; i<=M; i++) {
        if (totalTime % rides[i] == 0) N--;
        if (N == 0) return i;
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for (int i=1; i<=M; i++) {
        cin >> rides[i];
        rideCnt[rides[i]]++;
    }
    
    cout << findLastRide();

    return 0;
}
