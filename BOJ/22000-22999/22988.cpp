#include <iostream>
#include <algorithm>

using namespace std;

long long N, X;
long long arr[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> X;
    
    for(int i=0; i<N; i++) cin >> arr[i];
    
    sort(arr, arr+N);
    
    int lo = 0, hi = N-1;
    int cnt = 0;
    
    while (hi >= 0 && arr[hi] == X) {  // 원래부터 꽉찬 것 카운트
        cnt++;
        hi--;
        N--;
    }
    
    while (lo < hi) {       // 한 번만 합쳐도 꽉차게 되는 쌍 카운트
        while (lo < hi && (arr[lo] + arr[hi]) * 2 < X) lo++;    // 합이 절반이상이면
        
        if (lo < hi) {
            lo++;
            hi--;
            cnt++;
            N -= 2;
        }
    }
    
    cnt += N / 3;       // 나머지는 두 번 합쳐야 꽉 찬다.
    
    cout << cnt;

    return 0;
}
