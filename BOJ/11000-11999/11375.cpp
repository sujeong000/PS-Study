#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

const int MAX = 1001;

int N, M;
vector<int> works[MAX];
int owner[MAX];
bool visit[MAX];

bool DFS(int curr) {
    if (visit[curr]) return false;
    visit[curr] = true;
    
    for (auto work: works[curr]) {
        if (!owner[work] || DFS(owner[work])) {
            owner[work] = curr;
            return true;
        }
    }
    
    return false;
}

int bipartite_match() {
    int ret = 0;
    
    for (int i=1; i<=N; i++) {
        memset(visit, 0, sizeof(visit));
        if (DFS(i)) ret++;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    int k, w;
    for (int i=1; i<=N; i++) {
        cin >> k;
        
        for (int j=0; j<k; j++) {
            cin >> w;
            works[i].push_back(w);
        }
    }
    
    cout << bipartite_match();

    return 0;
}
