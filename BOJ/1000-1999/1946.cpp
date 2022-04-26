#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
const int MAX = 100001;

int T, N;
pii arr[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    while (T--) {
        cin >> N;
        
        int a, b;
        for (int i=0; i<N; i++) {
            cin >> a >> b;
            arr[i] = {a, b};
        }
        
        sort(arr, arr+N);
    
        int min_b = N+1;
        int cnt = 0;
        for (int i=0; i<N; i++) {
            if (arr[i].second > min_b) cnt++;
            min_b = min(min_b, arr[i].second);
        }
        
        cout << N - cnt << "\n";
    }

    return 0;
}
