#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

const int MAX = 200001;
int M, N;
int parent[MAX], sz[MAX];
priority_queue<piii, vector<piii>, greater<piii>> edges;

int find(int n) {
    if (parent[n] == n) return n;
    
    return parent[n] = find(parent[n]);
}

void merge(int a, int b) {
    a = find(a); b = find(b);
    
    if (a == b) return;
    if (sz[a] > sz[b]) swap(a, b);
    
    parent[a] = b;
    sz[b] += sz[a];
}

int kruskal() {
    int ret = 0;
    int cnt = 0;
    
    while (cnt < M-1) {
        piii curr = edges.top(); edges.pop();
        
        int z = curr.first;
        int x = curr.second.first;
        int y = curr.second.second;
        
        if (find(x) != find(y)) {
            ret += z;
            merge(x, y);
            cnt++;
        }
    }
    
    return ret;
}

void init_testcase() {
    while (!edges.empty()) edges.pop();
    
    for (int i=0; i<MAX; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while (true) {
        cin >> M >> N;
        if (M == 0 && N == 0) break;
        
        init_testcase();
        
        int x, y, z;
        int sum = 0;
        
        for (int i=0; i<N; i++) {
            cin >> x >> y >> z;
            sum += z;
            edges.push({z, {x, y}});
        }
        
        cout << sum - kruskal() << "\n";   
    }
    
    return 0;
}
