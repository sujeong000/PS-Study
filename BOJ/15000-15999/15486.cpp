#include <iostream>
#include <string.h>

using namespace std;
typedef pair<int, int> pii;
const int MAX = 15000000;

int N;
pii arr[MAX];
int cache[MAX];

int dp(int idx) {
    if (idx == N) return 0;
    
    int& ret = cache[idx];
    if (cache[idx] != -1) return ret;
    
    // 오늘 회의 선택 안하는 경우
    ret = dp(idx+1);
    
    // 오늘 회의 선택하는 경우
    int nidx = idx + arr[idx].first;
    if (nidx <= N) {
        ret = max(ret, arr[idx].second + dp(nidx));
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
        int t, p;
        cin >> t >> p;
        arr[i] = {t, p};
    }
    
    cout << dp(0);

    return 0;
}
