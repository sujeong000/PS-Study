#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

int N;
int arr[101];
bool visit[101];
vector<int> ans;

void DFS(int curr, int start) {
    if (visit[curr]) {
        if (start == curr) ans.push_back(curr);
        return;
    }
    
    visit[curr] = true;
    DFS(arr[curr], start);
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
        DFS(i, i);
    }
    
    cout << ans.size() << "\n";
    for (auto x: ans) cout << x << "\n";

    return 0;
}
