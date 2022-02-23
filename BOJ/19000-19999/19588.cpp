#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<long long, long long> pll;

int N, M, Q;
pll members[100001];
long long pxor[100001];       // 1-i번째 수까지 xor한 값
long long pxor_sum[100001];   // i번째 수까지 M개씩 xor한 값들을 더한 값

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    long long x, y;
    
    for(int i=1; i<=N; i++) {
        cin >> x >> y;
        members[i] = {x, y};
    }
    
    sort(members+1, members+1+N);   // 가장 큰 수 두개씩 곱하면 최대가 됨
    
    for (int i=1; i<=N; i++) {
        pxor[i] = pxor[i-1] ^ members[i].second;
    }
    
    for (int i=M; i<=N; i++) {
        pxor_sum[i] = pxor_sum[i-M] + (pxor[i] ^ pxor[i-M]);
    }
    
    cin >> Q;
    
    int a, b;
    
    while (Q--) {
        cin >> a >> b;
        cout << pxor_sum[N-b] - pxor_sum[N-b-a*M] << "\n";
    }
    
    return 0;
}
