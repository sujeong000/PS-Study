#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX = 81;
int N, M, cnt;
int match[MAX*MAX];
vector<int> adj[MAX*MAX];
bool arr[MAX][MAX], visit[MAX*MAX];

int dr[] = {-1, -1, 0, 0, 1, 1};
int dc[] = {-1, 1, -1, 1, -1, 1};

bool dfs(int curr) {
    if (visit[curr]) return false;
    visit[curr] = true;
    
    for (auto next : adj[curr]) {
        if (match[next] == -1 || dfs(match[next])) {
            match[next] = curr;
            return true;
        }
    }
    
    return false;
}

int bipartite_match() {
    int ret = 0;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j+=2) {
            if (!arr[i][j]) continue;
            memset(visit, 0, sizeof(visit));
            if (dfs(i*M+j)) ret++;
        }
    }
    
    return ret;
}

void init_testcase() {
    for (int i=0; i<MAX*MAX; i++) adj[i].clear();
    memset(match, -1, sizeof(match));
    cnt = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        init_testcase();
        
        cin >> N >> M;
        for (int i=0; i<N; i++) {
            string s;
            cin >> s;
            for (int j=0; j<M; j++) {
                arr[i][j] = s[j] == '.';
                if (arr[i][j]) cnt++;
            }
        }
        
        // 컨닝하는 열과 당하는 열은 항상 짝홀/홀짝임
        // 컨닝하는 칸과 당하는 칸을 간선으로 이은 뒤, 최대 독립집합을 구하면 됨
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j+=2) {
                if (!arr[i][j]) continue;
                
                int idx = i*M + j;
                for (int k=0; k<6; k++) {
                    int adj_r = i + dr[k];
                    int adj_c = j + dc[k];
                    if (adj_r < 0 || adj_r >= N || adj_c < 0 || adj_c >= M || !arr[adj_r][adj_c]) continue;
                    
                    int adj_idx = adj_r*M + adj_c;
                    adj[idx].push_back(adj_idx);
                }
            }
        }
        
        // Maximum Independent Set = U - Minimum Vertex Cover
        // Minimum Vertex Cover = Maximum Bipartite Match
        cout << cnt - bipartite_match() << "\n";
    }

    return 0;
}
