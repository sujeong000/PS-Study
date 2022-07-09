#include <iostream>
#include <unordered_map>

using namespace std;

int N, M;
unordered_map<int, bool> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    for (int i=0; i<N; i++) {
        int x; cin >> x;
        mp[x] = true;
    }
    
    cin >> M;
    
    for (int i=0; i<M; i++) {
        int x; cin >> x;
        if (mp[x]) cout << 1 << " ";
        else cout << 0 << " ";
    }

    return 0;
}
