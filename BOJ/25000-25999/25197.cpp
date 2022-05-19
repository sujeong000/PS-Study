#include <iostream>
#include <string.h>

using namespace std;

typedef long double ld;

ld N, K;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cout << fixed;
    cout.precision(12);
    
    cin >> N >> K;
    
    // 두 곰곰이가 있을 때, 둘이 식사할 확률 = K/K^2 = K/1
    // 모든 두 곰곰쌍(총 N(N-1)/2개)을 고려해주면
    cout << N*(N-1)/2 * (1/K);

    return 0;
}
