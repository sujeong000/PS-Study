#include <iostream>

using namespace std;

typedef long long ll;

ll sumAllNums(int n, ll power) {
    ll sum = 0;
    
    while (n > 0) {
        sum += power * (n % 10);
        n /= 10;
    }
    
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int L, U;
    cin >> L >> U;
    
    ll power = 1;
    ll sum = 0;
    
    while (L <= U) {
        while (L % 10 != 0 && L <= U) sum += sumAllNums(L++, power);
        if (L > U) break;
        while (U % 10 != 9 && L <= U) sum += sumAllNums(U--, power);
        if (L > U) break;
        
        U /= 10;
        L /= 10;
        
        sum += power * (U - L + 1) * 45;
        
        power *= 10;
    }
    
    cout << sum;

    return 0;
}
