#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int A, B, N, M;
bool visit[100001];
queue<pii> q;

int bfs() {
    q.push({N, 0});
    visit[N] = true;
    
    while (!q.empty()) {
        int curr = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        if (curr == M) return dist;
        
        int next[] = {curr+1, curr-1, curr-A, curr+A, curr-B, curr+B, curr*A, curr*B};
        for (int i=0; i<8; i++) {
            if (next[i] < 0 || next[i] > 100000 || visit[next[i]]) continue;
            visit[next[i]] = true;
            q.push({next[i], dist+1});
        }
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> A >> B >> N >> M;
    
    cout << bfs();

    return 0;
}
