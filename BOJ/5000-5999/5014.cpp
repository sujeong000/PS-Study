// -----------------------------
// 1. 그리디
// -----------------------------
#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;

int calc_min_dist() {
    for (int i=0; i <= 1000000; i++) {
        if (S == G) return i;
        if (S + U > F && S - D < 1) return -1;
        
        if (S < G) {
            if (S + U <= F) S += U;
            else S -= D;
        }
        else {
            if (S - D >= 1) S -= D;
            else S += U;
        }
    }
    
    return -1;
}

int main()
{
    cin >> F >> S >> G >> U >> D;
    
    int result = calc_min_dist();
    
    if (result == -1) cout << "use the stairs";
    else cout << result;
    
    return 0;
}


// --------------------------
// 2.BFS
// --------------------------
#include <iostream>
#include <queue>

using namespace std;

int F, S, G, U, D;
queue<int> q;
bool visit[1000001];
int dist[1000001];

int calc_min_dist() {
    visit[S] = true;
    q.push(S);
    
    while (!q.empty()) {
        int curr = q.front(); q.pop();
        
        if (curr == G) return dist[G];
        
        int up = curr + U;
        int down = curr - D;
        
        if (up <= F && !visit[up]) {
            dist[up] = dist[curr] + 1;
            visit[up] = true;
            q.push(up);
        }
        
        if (down > 0 && !visit[down]) {
            dist[down] = dist[curr] + 1;
            visit[down] = true;
            q.push(down);
        }
    }
    
    return -1;
}

int main()
{
    cin >> F >> S >> G >> U >> D;
    
    int result = calc_min_dist();
    
    if (result == -1) cout << "use the stairs";
    else cout << result;
    
    return 0;
}
