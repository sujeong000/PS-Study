#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

const int MAX = 300001;

struct Change {
    int idx;
    int before;
    int after;
};

int N, M;
Change changes[MAX];
vector<int> befores[MAX];   // befores[i]: Ui가 i인 차원이동들의 번호
int cache[MAX];

int lower_bound(int at, int val) {
    int lo = 0, hi = befores[at].size();
    
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (befores[at][mid] < val) lo = mid + 1;
        else hi = mid;
    }
    
    return lo;
}

// dp(idx): idx번째 차원이동을 탔을 때 최종 값
int dp(int idx) {
    int& ret = cache[idx];
    if (ret != -1) return ret;
    
    int v = changes[idx].after;
    int lb = lower_bound(v, idx);
    if (lb == befores[v].size()) return v;  // 더이상 차원이동을 타지 않는 경우 종료
    else return ret = dp(befores[v][lb]);   // befores[v][lb]: 다음으로 타게되는 차원 이동
}

// f(n): 음료수 종류 n이 M번의 차원 이동을 거친 뒤의 최종값
int f(int n) {
    if (befores[n].empty()) return n;
    else return dp(befores[n][0]);  // befores[n][0]: 최초로 타는 차원이동 번호
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> N >> M;
    
    int u, v;
    for (int i=0; i<M; i++) {
        cin >> u >> v;
        changes[i] = {i, u, v};
        befores[u].push_back(i);
    }
    
    for (int i=1; i<=N; i++) cout << f(i) << " ";

    return 0;
}
