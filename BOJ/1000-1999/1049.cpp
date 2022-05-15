#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX = 51, INF = 987654321;

int N, M;
int package[MAX], individual[MAX];

int main()
{
    cin >> N >> M;
    for (int i=0; i<M; i++) {
        cin >> package[i] >> individual[i];
    }
    
    sort(package, package+M);
    sort(individual, individual+M);
    
    int ans = INF;
    for (int i=0; i<=N; i++) {
        int package_num = (N-i)/6;
        if ((N-i) % 6 != 0) package_num++;
        ans = min(ans, individual[0]*i + package[0]*package_num);
    }
    
    cout << ans;

    return 0;
}
