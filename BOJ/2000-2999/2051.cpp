#include <iostream>
#include <string.h>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef long long ll;

const int MAX = 1001;
int N, M, Acnt, Bcnt;
int match[MAX], owner[MAX];
bool adj[MAX][MAX], visit[MAX], notMvcA[MAX], mvcB[MAX];

bool bm_dfs(int curr) {
    if (visit[curr]) return false;
    visit[curr] = true;
    
    for (int i=1; i<=M; i++) {
        if (!adj[curr][i]) continue;
        if (!owner[i] || bm_dfs(owner[i])) {
            match[curr] = i;
            owner[i] = curr;
            return true;
        }
    }
    
    return false;
}

int bipartite_match() {
    int ret = 0;
    
    for (int i=1; i<=N; i++) {
        memset(visit, 0, sizeof(visit));
        if (bm_dfs(i)) ret++;
    }
    
    return ret;
}

void ap_dfs(int curr) {
    // mvcA = match && !alternatingPath
    if (notMvcA[curr]) return;
    notMvcA[curr] = true;
    Acnt++;
    
    for (int b=1; b<=M; b++) {
        if (!adj[curr][b]) continue;
        if (owner[b] && !mvcB[b]) {
            // mvcB = match && alternatingPath
            mvcB[b] = true;
            Bcnt++;
            ap_dfs(owner[b]);
        }
    }
}

int minimum_vertext_cover() {
    int match_cnt = bipartite_match();
    
    for (int i=1; i<=N; i++) {
        // 매칭에 포함되지 않은 A그룹 정점에 대해 alternating path 찾기
        if (!match[i]) ap_dfs(i);
    }
    
    return match_cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    int n, x;
    for (int i=1; i<=N; i++) {
        cin >> n;
        for (int j=0; j<n; j++) {
            cin >> x;
            adj[i][x] = true;
        }
    }
    
    cout << minimum_vertext_cover() << "\n";
    
    cout << N - Acnt << " ";
    for (int i=1; i<=N; i++) {
        if (!notMvcA[i]) cout << i << " ";
    }
    cout << "\n";
    
    cout << Bcnt << " ";
    for (int i=1; i<=M; i++) {
        if (mvcB[i]) cout << i << " ";
    }
    cout << "\n";

    return 0;
}
