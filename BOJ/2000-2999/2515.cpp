#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;
typedef pair<int, int> pii;

int N, S;
vector<pii> paintings;
int previous[300001];   // previous[i] = i번 그림보다 S이상 작은 그림 중 가장 오른쪽에 있는 그림
int cache[300001];


// dp(idx): idx번 그림까지 고려했을 때 최대 판매액
int dp(int idx) {
    if (idx == 0) return paintings[0].second;
    
    int& ret = cache[idx];
    if (ret != -1) return ret;
    
    ret = max(paintings[idx].second, dp(idx-1));
    if (previous[idx] != -1) {
        ret = max(ret, dp(previous[idx]) + paintings[idx].second);
    }
    
    return ret;
}

int upper_bound(int x) {
    int lo = 0, hi = N;
    
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (paintings[mid].first <= x) lo = mid+1;
        else hi = mid;
    }
    
    return lo;
}

void calcPrevious() {
    for (int i=0; i<N; i++) {
        int ub = upper_bound(paintings[i].first-S);
        previous[i] = ub-1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N >> S;
    
    for (int i=0; i<N; i++) {
        int h, c;
        cin >> h >> c;
        
        paintings.push_back({h, c});
    }
    
    sort(paintings.begin(), paintings.end());
    calcPrevious();
    
    cout << dp(N-1);
    
    return 0;
}
