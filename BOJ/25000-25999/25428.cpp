#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int N;
ll arr[100001];
vector<piii> edges;
int parent[100001], sz[100001];
int maxSz;

void initUnionFind() {
    for (int i=1; i<=N; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    a = find(a); b = find(b);
    
    if (a == b) return;
    if (sz[a] < sz[b]) swap(a, b);
    
    parent[b] = a;
    sz[a] += sz[b];
    maxSz = max(maxSz, sz[a]);
}

ll optimize() {
    ll ret = 0;
    
    initUnionFind();
    for (int i=1; i<=N; i++) ret = max(ret, arr[i]);    // 교실 하나만 고르는 경우
    sort(edges.begin(), edges.end(), greater<piii>());
    
    for (auto edge: edges) {
        ll c = edge.first;  // 각 교실에서 훔칠 분필 수
        int u = edge.second.first;
        int v = edge.second.second;
        
        merge(u, v);
        ret = max(ret, c*maxSz);
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i=1; i<=N; i++) cin >> arr[i];
    for (int i=0; i<N-1; i++) {
        int u, v;
        cin >> u >> v;
        
        int c = min(arr[u], arr[v]);
        edges.push_back({c, {u, v}});
    }
    
    cout << optimize();
    
    return 0;
}
