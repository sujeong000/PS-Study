#include <iostream>
#include <string.h>
#include <set>
#include <vector>

using namespace std;

int N;
int arr[101];
bool visit[101];
set<int> ans;

void DFS(int curr, vector<int> route) {
    if (visit[curr]) {
        if (route[0] == curr) {
            for (auto node: route) {
                ans.insert(node);
            }
        }
        
        return;
    }
    
    visit[curr] = true;
    route.push_back(curr);
    DFS(arr[curr], route);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N;
    for (int i=1; i<=N; i++) cin >> arr[i];
    
    // 사이클에 속한 노드들을 전부 선택
    for (int i=1; i<=N; i++) {
        memset(visit, 0, sizeof(visit));
        DFS(i, {});
    }
    
    cout << ans.size() << "\n";
    for (auto x: ans) cout << x << "\n";

    return 0;
}
