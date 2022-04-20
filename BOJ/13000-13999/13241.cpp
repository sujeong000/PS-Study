#include <iostream>

using namespace std;

typedef long long ll;

ll A, B;

ll gcd(int a, int b) {
    if (b == 0) return a;
    
    return gcd(b, a%b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> A >> B;
    if (A < B) swap(A, B);
    cout << A*B / gcd(A, B);

    return 0;
}
