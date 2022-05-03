#include <iostream>
#include <queue>

using namespace std;

const int MAX = 10001, INF = 987654321;
typedef pair<int, int> pii;

int N, R, cnt;
int lc[MAX], rc[MAX], pos[MAX], min_pos[MAX], max_pos[MAX], par[MAX];
queue<pii> q;

// 노드들의 x좌표는 중위순회 결과와 같다.
void calc_pos(int idx) {
    int l = lc[idx], r = rc[idx];
    
    if (l != -1) calc_pos(l);
    pos[idx] = ++cnt;
    if (r != -1) calc_pos(r);
}

pii find_max_width() {
    for (int i=0; i<MAX; i++) min_pos[i] = INF;
    
    q.push({R, 1});
    while (!q.empty()) {
        int idx = q.front().first;
        int level = q.front().second;
        q.pop();
        
        min_pos[level] = min(min_pos[level], pos[idx]);
        max_pos[level] = max(max_pos[level], pos[idx]);
        
        int l = lc[idx], r = rc[idx];
        if (l != -1) q.push({l, level+1});
        if (r != -1) q.push({r, level+1});
    }
    
    pii ret = {0, 0};
    for (int i=1; i<MAX; i++) {
        int level_width = max_pos[i] - min_pos[i] + 1;
        if (ret.second < level_width || (ret.second == level_width && ret.first > i)) {
            ret = {i, level_width};
        }
    }
    
    return ret;
}

void find_root() {
    for (int i=1; i<=N; i++) {
        if (par[i] == 0) {
            R = i;
            break;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    int x, l, r;
    for (int i=0; i<N; i++) {
        cin >> x >> l >> r;
        
        lc[x] = l;
        rc[x] = r;
        if (l != -1) par[l] = x;
        if (r != -1) par[r] = x;
    }
    
    find_root();
    calc_pos(R);
    pii ans = find_max_width();
    
    cout << ans.first << " " << ans.second;
    
    return 0;
}
