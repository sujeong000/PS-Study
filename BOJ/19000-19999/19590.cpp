#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    long long N, x;
    
    cin >> N;
    
    long long sum = 0, max_val = 0;
    
    for (int i=0; i<N; i++) {
        cin >> x;
        sum += x;
        max_val = max(max_val, x);
    }
    
    sum -= max_val;
    
    // 1. 가장 많이 남은 두 종류에서 1개씩 꺼내서 부딪히면 된다. 전체 개수가 홀수개면 마지막 하나는 못부딪힘.
    // 2. 최대값보다 나머지의 합이 작으면 최대는 계속 최대로 남게 된다.
    if (max_val < sum) cout << (sum + max_val) % 2;
    else cout << max_val - sum;
    
    return 0;
}
