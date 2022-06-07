#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
const int MAX = 1001;

int N, M, K;
vector<pii> adjs[MAX];
priority_queue<int> sp[MAX];    // 1->i로 가는 최단 k개의 경로 저장

void dijkstra() {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    sp[1].push(0);
    pq.push({0, 1});
    
    while (!pq.empty()) {
        int curr = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();
        
        for (auto adj: adjs[curr]) {
            int next = adj.first;
            int nextDist = currDist + adj.second;
            
            if (sp[next].size() < K) {
                sp[next].push(nextDist);
                pq.push({nextDist, next});
            }
            else if (sp[next].top() > nextDist) {
                sp[next].pop();
                sp[next].push(nextDist);
                pq.push({nextDist, next});
            }
        }
    }
}

int main()
{
    cin >> N >> M >> K;
    
    for (int i=0; i<M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adjs[a].push_back({b, c});
    }
    
    dijkstra();
    
    for (int i=1; i<=N; i++) {
        if (sp[i].size() < K) cout << "-1\n";
        else cout << sp[i].top() << "\n";
    }

    return 0;
}
