#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (a < b) swap(a, b);
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    cin >> N;
    
    vector<int> v(N);
    for (int i=0; i<N; i++) cin >> v[i];
    
    vector<int> pgcd(N), sgcd(N);
    pgcd[0] = v[0];
    sgcd[N-1] = v[N-1];
    for (int i=1; i<N; i++) {
        pgcd[i] = gcd(pgcd[i-1], v[i]);
        sgcd[N-1-i] = gcd(sgcd[N-i], v[N-1-i]);
    }
    
    int maxGCD = -1, idx;
    for (int i=0; i<N; i++) {
        int GCD;
        if (i == 0) GCD = sgcd[1];
        else if (i == N-1) GCD = pgcd[N-2];
        else GCD = gcd(pgcd[i-1], sgcd[i+1]);
        
        if (GCD > maxGCD) {
            idx = i;
            maxGCD = GCD;
        }
    }
    
    if (v[idx] % maxGCD == 0) cout << -1;
    else cout << maxGCD << " " << v[idx];
    
    return 0;
}
