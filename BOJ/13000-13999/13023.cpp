#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int N, M;
vector<int> adjs[2001];
bool visit[2001];

bool DFS(int curr, int depth) {
    if (depth >= 4) return true;
    visit[curr] = true;
    
    for (int next: adjs[curr]) {
        if (visit[next]) continue;
        if (DFS(next, depth+1)) return true;
    }
    
    visit[curr] = false;
    return false;
}

bool check() {
    for (int i=0; i<N; i++) {
        if (DFS(i, 0)) return true;
    }
    
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        int a, b;
        cin >> a >> b;
        adjs[a].push_back(b);
        adjs[b].push_back(a);
    }
    
    if (check()) cout << 1;
    else cout << 0;
    
    return 0;
}
