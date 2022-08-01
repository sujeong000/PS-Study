#include <iostream>
#include <set>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int N, K, M;
vector<int> adjs[101001];

int BFS(int from, int to) {
    queue<pii> q;
    vector<bool> visit(101001, 0);
    
    q.push({1, from});
    visit[from] = true;
    
    while (!q.empty()) {
        int dist = q.front().first;
        int curr = q.front().second;
        q.pop();
        
        if (curr == to) return dist;
        
        for (auto next: adjs[curr]) {
            int nDist = (next > N) ? dist : dist + 1;
            
            if (!visit[next]) {
                q.push({nDist, next});
                visit[next] = true;
            }
        }
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K >> M;
    for (int i=1; i<=M; i++) {
        for (int j=0; j<K; j++) {
            int temp; cin >> temp;
            // 하이퍼튜브도 노드로 처리한다
            // N+i번 노드 = i번 하이퍼튜브
            adjs[temp].push_back(N+i);
            adjs[N+i].push_back(temp);
        }
    }
    
    cout << BFS(1, N);

    return 0;
}
