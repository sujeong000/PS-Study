#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

const int MAX = 10'001;

int N;
int depth[MAX], parent[MAX];
vector<int> children[MAX];

void dfs(int curr) {
    for (auto child: children[curr]) {
        depth[child] = depth[curr] + 1;
        dfs(child);
    }
}

int NCA(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);
    
    // a를 b와 같은 높이까지 끌어올리기
    while (depth[a] > depth[b]) {
        a = parent[a];
    }
    
    // 공통 조상을 만날 때까지 끌어올리기
    while (a != b) {
        a = parent[a];
        b = parent[b];
    }
    
    return a;
}

void initTestcase() {
    for (int i=0; i<MAX; i++) {
        children[i].clear();
        parent[i] = i;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; cin >> T;
    while (T--) {
        initTestcase();
        
        cin >> N;
        int a, b;
        for (int i=0; i<N-1; i++) {
            cin >> a >> b;
            children[a].push_back(b);
            parent[b] = a;
        }
        
        for (int i=1; i<=N; i++) {
            if (parent[i] == i) {   // 루트
                depth[i] = 0;
                dfs(i); // dfs로 모든 정점의 깊이를 구합니다.
                break;
            }
        }
        
        cin >> a >> b;
        cout << NCA(a, b) << "\n";
    }
    
    return 0;
}
