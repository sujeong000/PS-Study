#include <iostream>
#include <algorithm>

using namespace std;

int N, K, T;
int nadori[100001];

int main()
{
    cin >> N >> K >> T;
    
    long long sum = 0;
    
    for(int i=0; i<N; i++) {
        cin >> nadori[i];
        sum += nadori[i];
    }
    
    if (sum % K != 0) cout << "NO";     // 총 나도리 합이 K의 배수가 아니면 불가능
    else {
        sort(nadori, nadori+N);
        
        long long cnt = 0;
        
        for(int i=0; i<sum/K; i++) {    // 가장 큰 sum/K개 바구니에 나도리를 모음
            cnt += K - nadori[N-1-i];   // K - nadori[i] = i번째 바구니를 채우기 위한 연산 횟수
        }
        
        if (cnt > T) cout << "NO";
        else cout << "YES";
    }

    return 0;
}
