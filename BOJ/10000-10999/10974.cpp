#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> permu;

void DFS(int depth, int mask) {
    if (depth == N) {
        for (auto x : permu) cout << x << " ";
        cout << "\n";
        return;
    }
    
    for (int i=1; i<=N; i++) {
        if ((mask & (1 << i)) != 0) continue;
        
        permu.push_back(i);
        DFS(depth+1, mask|(1<<i));
        permu.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    DFS(0, 0);

    return 0;
}
