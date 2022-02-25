#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long N, K;
long long arr[200001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> K;
    
    for(int i=0; i<N; i++) cin >> arr[i];
    
    sort(arr, arr+N);
    
    long long min_time = 1000000000000000001;
    
    for(int i=1; i<N; i++) {    // 0~(i-1)번째와 i~끝까지로 나눔
        long long v1 = arr[0] * i;
        long long v2 = arr[i] * (N-i);
        long long t = K / (v1 + v2);
        
        if (K % (v1 + v2) != 0) t++;    // 나머지 처리
        
        min_time = min(min_time, t);
    }
    
    cout << min_time;

    return 0;
}
