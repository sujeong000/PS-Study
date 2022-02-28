#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <map>
#include <cmath>
#include <vector>
#include <stack>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int N;
vector<pii> adj[100001];
bool visit[100001];
int height[100001];
int max_size = 0;

void dfs(int idx) {
    visit[idx] = true;
    height[idx] = 1;
    
    for(int i=0; i<adj[idx].size(); i++) {
        int next = adj[idx][i].second;
        
        if (visit[next]) continue;
        
        dfs(next);
        
        adj[idx][i].first = height[next];
        height[idx] = max(height[idx], height[next] + 1);
    }
}

int find_max_depth(int from, int to) {
    for(int i=adj[to].size()-1; i>=0; i--) {
        if (adj[to][i].second != from) return adj[to][i].first;
    }
    
    return 0;
}

void dfs_find_max_size(int s) {
    visit[s] = true;
    
    for(int j=0; j<adj[s].size(); j++) {
        if (adj[s][j].first != 0) continue;
        adj[s][j].first = find_max_depth(s, adj[s][j].second) + 1;
    }
    
    sort(adj[s].begin(), adj[s].end());
    
    int sz = adj[s].size();
    if (sz >= 3) {
        max_size = max(max_size, 1 + adj[s][sz-1].first + adj[s][sz-2].first + adj[s][sz-3].first);    
    }
    
    for(int i=0; i<adj[s].size(); i++) {
        int next = adj[s][i].second;
        if (visit[next]) continue;
        
        dfs_find_max_size(next);
    }
}

void find_max_size() {
    for(int i=i; i<=N; i++) sort(adj[i].begin(), adj[i].end());
    memset(visit, 0, sizeof(visit));
    dfs_find_max_size(1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    
    int s, e;
    
    for(int i=0; i<N-1; i++) {
        cin >> s >> e;
        adj[s].push_back({0, e});
        adj[e].push_back({0, s});
    }
    
    dfs(1);
    find_max_size();

    cout << max_size;
    
    return 0;
}
