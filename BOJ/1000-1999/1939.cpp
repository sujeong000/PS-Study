#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int N, M, S, E;
int parent[10001], sz[10001];
piii edges[100001];

int find(int n) {
    if (n == parent[n]) return n;
    return parent[n] = find(parent[n]);
}

void merge(int a, int b) {
    a = find(a); b = find(b);
    
    if (a == b) return;
    
    if (sz[a] < sz[b]) swap(a, b);
    parent[b] = a;
    sz[a] += sz[b];
}

int calcMaxWeight() {
    for (int i=0; i<10001; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
    
    // 가중치가 큰 간선부터 두 공장이 이어질 때까지 선택한다
    sort(edges, edges+M, greater<piii>());
    
    for (auto edge: edges) {
        int c = edge.first;
        int a = edge.second.first;
        int b = edge.second.second;
        
        merge(a, b);
        
        if (find(S) == find(E)) return c;
    }
    
    return 1000000000;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    for (int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        edges[i] = {c, {a, b}};
    }
    
    cin >> S >> E;
    
    cout << calcMaxWeight();

    return 0;
}
