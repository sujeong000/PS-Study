#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll INF = 1e10;

struct Node {
    int bottle; // 왼쪽 물병인지 오른쪽 물병인지
    int x;      // bottle에 들어있는 양
    int full;   // 반대 물병이 비어있는지 꽉 차있는지(무조건 둘중에 하나)
};

int A, B, C, D;
ll dist[2][100001][2];
queue<Node> q;

Node toNode(int a, int b) {
    if (a == A) return {1, b, 1};
    if (a == 0) return {1, b, 0};
    if (b == B) return {0, a, 1};
    if (b == 0) return {0, a, 0};
    return {0, 0, 0};
}

void pushNext(int a, int b, int d) {
    Node next = toNode(a, b);
    
    if (dist[next.bottle][next.x][next.full] == INF) {
        dist[next.bottle][next.x][next.full] = d;
        q.push(next);
    }
}

ll BFS() {
    fill(&dist[0][0][0], &dist[0][0][0]+2*100001*2, INF);
    
    q.push({0, 0, 0});
    dist[0][0][0] = 0;
    
    while (!q.empty()) {
        Node curr = q.front(); q.pop();
        
        int bottle = curr.bottle;
        int x = curr.x;
        int full = curr.full;
        ll curr_dist = dist[bottle][x][full];
        
        int a = (bottle == 0) ? x : (full ? A : 0);
        int b = (bottle == 1) ? x : (full ? B : 0);
        
        if (a == C && b == D) return curr_dist;
        
        // fill A
        pushNext(A, b, curr_dist+1);
        // fill B
        pushNext(a, B, curr_dist+1);
        // empty A
        pushNext(0, b, curr_dist+1);
        // empty B
        pushNext(a, 0, curr_dist+1);
        // move from A to B
        pushNext(a+b-min(B, b+a), min(B, b+a), curr_dist+1);
        // move from B to A
        pushNext(min(A, a+b), a+b-min(A, a+b), curr_dist+1);
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> A >> B >> C >> D;
    cout << BFS();

    return 0;
}

