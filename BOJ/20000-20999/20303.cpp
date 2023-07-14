#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

const int MAX_N = 30'000;
const int MAX_K = 3'000;

struct CC {
    int cnt;    // 연결요소에 속하는 노드의 개수
    int sum;    // 속하는 모든 노드에 걸린 사탕 개수의 합
};

int N, M, K, CN;
int num_of_candy[MAX_N];
vector<int> adjs[MAX_N];
bool visited[MAX_N];
int w[MAX_N+1];
int v[MAX_N+1];

CC DFS(int curr) {
    visited[curr] = true;
    
    int cnt = 1;
    int sum = num_of_candy[curr];
    
    for (auto next: adjs[curr]) {
        if (!visited[next]) {
            auto temp = DFS(next);
            cnt += temp.cnt;
            sum += temp.sum;
        }
    }
    
    return {cnt, sum};
}

// 모든 연결요소를 찾는 함수
void findCC() {
    for (int i=0; i<N; i++) {
        if (visited[i]) continue;
        
        CN++;
        auto cc = DFS(i);
        w[CN] = cc.cnt;
        v[CN] = cc.sum;
    }
}

int findMaxNumOfCandy() {
    findCC();
    
    // dp[i][j]: K=j일 때, i번 연결요소까지 고려하여 뺏을 수 있는 사탕의 최대개수
    vector<vector<int>> dp(CN+1, vector<int>(K+1, 0));
    
    for (int i=1; i<=CN; i++) {
        for (int j=0; j<=K; j++) {
            // i번 연결요소를 선택하지 않는 경우
            dp[i][j] = dp[i-1][j];
            // i번 연결요소를 선택하는 경우
            if (w[i] < j) {
                dp[i][j] = max(dp[i][j], v[i] + dp[i-1][j-w[i]]);
            }
        }
    }
    
    return dp[CN][K];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M >> K;
    for (int i=0; i<N; i++) {
        cin >> num_of_candy[i];
    }
    for (int i=0; i<M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adjs[u].push_back(v);
        adjs[v].push_back(u);
    }
    
    cout << findMaxNumOfCandy();
}
