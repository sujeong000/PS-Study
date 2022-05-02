#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int MAX = 123457;

int N;
int v[MAX];
bool visit[MAX];
vector<int> adj[MAX];

ll DFS(int curr) {
    visit[curr] = true;
    
    ll ret = 0;
    for (auto next : adj[curr]) {
        if (visit[next]) continue;
        ret += DFS(next);
    }
    ret = max((ll)0, ret+v[curr]);
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    char t;
    int a, p;
    for (int i=2; i<=N; i++) {
        cin >> t >> a >> p;
        
        v[i] = t == 'W' ? -a : a;
        adj[i].push_back(p);
        adj[p].push_back(i);
    }
    
    cout << DFS(1);

    return 0;
}
