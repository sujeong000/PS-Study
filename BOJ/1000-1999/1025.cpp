#include <iostream>
#include <cmath>
#include <map>

using namespace std;

int N, M;
int arr[10][10];
map<int, bool> mp;

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    
    for (long long i=0; i<100000; i++) {
        if (i*i < 1000000000) mp[i*i] = true;
    }
    
    cin >> N >> M;
    
    int x;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%1d", &x);
            arr[i][j] = x;
        }
    }
    
    int ans = -1;
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            if (arr[i][j] == 0 || arr[i][j] == 1 || arr[i][j] == 4 || arr[i][j] == 9) {
                ans = max(ans, arr[i][j]);
            }
            
            for (int di=-N; di<N; di++) {
                for (int dj=-M; dj<M; dj++) {
                    if (di == 0 && dj == 0) continue;
                    
                    int x = 0;
                    int r = i;
                    int c = j;
                    
                    while (0 <= r && r < N && 0 <= c && c < M) {
                        x *= 10;
                        x += arr[r][c];
                        
                        if (x != 0 && mp.find(x) != mp.end()) ans = max(ans, x);
                        
                        r += di;
                        c += dj;
                    }
                }
            }
        }
    }
    
    cout << ans;

    return 0;
}
