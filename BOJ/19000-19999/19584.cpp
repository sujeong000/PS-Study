#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
typedef pair<int, int> pii;

int N, M;

int loc[200001];
map<int, long long> s, e;

long long calc_max_destruction() {
    sort(loc+1, loc+N+1);
    
    long long max_destrction = 0;
    long long destruction = 0;
    
    for(int i=N; i>=1; i--) {
        if (i != N && loc[i] == loc[i+1]) continue;
        
        destruction += s[loc[i]];
        max_destrction = max(max_destrction, destruction);
        destruction -= e[loc[i]];
    }
    
    return max_destrction;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    int x, y;
    for(int i=1; i<=N; i++) {
        cin >> x >> y;
        loc[i] = y;
        s[y] = 0;
        e[y] = 0;
    }
    
    int u, v, c;
    for(int i=0; i<M; i++) {
        cin >> u >> v >> c;
        
        if (loc[u] > loc[v]) {
            s[loc[u]] += c;
            e[loc[v]] += c;
        }
        else {
            s[loc[v]] += c;
            e[loc[u]] += c;
        }
    }
    
    cout << calc_max_destruction();

    return 0;
}
