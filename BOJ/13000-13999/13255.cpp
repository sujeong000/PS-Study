#include <iostream>
#include <string.h>

using namespace std;

typedef long double ld;

int N, K;
ld A[51];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cout << fixed;
    cout.precision(12);
    
    cin >> N >> K;
    for (int i=0; i<K; i++) cin >> A[i];
    
    ld front = N;   // 현재 앞면인 동전개수의 기댓값
    for (int i=0; i<K; i++) {
        // 현재 앞면은 뒤집히면 안되고, 현재 뒷면은 뒤집혀야 한다.
        // 각 동전이 뒤집힐 확률은 A[i]/N으로 동일하다.
        front = front*(1-A[i]/N) + (N-front)*(A[i]/N);
    }
    
    cout << front;

    return 0;
}
