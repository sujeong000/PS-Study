#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

const int MAX = 1001;

int N, M;
vector<int> works[MAX];
int owner[MAX];
bool visit[MAX];

bool DFS(int emp) {
    if (visit[emp]) return false;
    visit[emp] = true;
    
    for (auto work: works[emp]) {
        if (!owner[work] || DFS(owner[work])) {
            owner[work] = emp;
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
    
    int wn, work;
    for (int emp=1; emp<=N; emp++) {
        cin >> wn;
        
        for (int i=0; i<wn; i++) {
            cin >> work;
            works[emp].push_back(work);
        }
    }
    
    cout << bipartite_match() + bipartite_match();

    return 0;
}
