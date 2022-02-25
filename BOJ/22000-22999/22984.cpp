#include <iostream>
#include <algorithm>

using namespace std;

typedef long double ld;

int N;
ld p[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    
    ld sum = 0;
    
    for(int i=0; i<N; i++) {
        cin >> p[i];
        
        sum += p[i];    // 기존 전구 기댓값
        if (i != 0) sum += p[i]*(1-p[i-1]) + (1-p[i])*p[i-1];   // 추가 전구 기댓값, 이웃 전구 중 하나만 켜져야 함
    }
    
    cout << fixed;
    cout.precision(15);
    cout << sum;

    return 0;
}
