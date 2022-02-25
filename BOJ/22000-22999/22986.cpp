#include <iostream>

using namespace std;

long long An(long long n) { // 지구의 크기가 N일때 전체 면적
    if (n < 0) return 0;
    return 2 * n * (n+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long T, N, K;
    
    cin >> T;
    
    while (T--) {
        cin >> N >> K;
        
        cout << An(N) - An(N-K-1) << "\n";  // 끝까지의 거리가 K 이하여야 도달 가능
    }

    return 0;
}
