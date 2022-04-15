#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef long long ll;
const int MAX = 1001;

int N, M, A, B, C, entrance;
int parent[MAX], sz[MAX];
piii roads[MAX*MAX];

int find(int x) {
    if (parent[x] == x) return x;
    
    return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
    a = find(a); b = find(b);
    if (a == b) return;
    
    if (sz[a] > sz[b]) swap(a, b);
    parent[a] = b;
    sz[b] += sz[a];
}

void init_union_find() {
    for (int i=0; i<MAX; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int mst() {
    ll ret = 1 - entrance;
    int cnt = 0;
    
    init_union_find();
    for (int i=0; i<M; i++) {
        if (cnt == N-1) break;
        
        piii road = roads[i];
        int s = road.second.first;
        int e = road.second.second;
        int c = road.first;
        if (find(s) == find(e)) continue;
        
        merge(s, e);
        if (c == 0) ret++;
        cnt++;
    }
    
    return ret * ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    cin >> A >> B >> entrance;
    for (int i=0; i<M; i++) {
        cin >> A >> B >> C;
        roads[i] = {C, {A, B}};
    }
    
    sort(roads, roads+M, greater<piii>());
    ll min_cost = mst();
    
    sort(roads, roads+M, less<piii>());
    ll max_cost = mst();

    cout << max_cost - min_cost;
    
    return 0;
}
