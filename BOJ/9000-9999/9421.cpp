#include <string>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;

const int MAX = 1e6+1;
const int VISITED = -2;

bool isPrime[MAX];
int cache[MAX];

void getPrimes() {
    for (int i=2; i<MAX; i++) isPrime[i] = true;
    
    for (int i=2; i<MAX; i++) {
        if (!isPrime[i]) continue;
        
        for (int j=i+i; j<MAX; j+=i) {
            isPrime[j] = false;
        }
    }
}

bool check(int x) {
    if (x == 1) return true;
    
    int& ret = cache[x];
    if (ret == VISITED) return false;
    if (ret != -1) return ret;
    
    ret = VISITED;
    int nx = 0;
    
    while (x) {
        nx += (x % 10) * (x % 10);
        x /= 10;
    }
    
    return ret = check(nx);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    getPrimes();
    
    int n;
    cin >> n;
    
    for (int i=2; i<=n; i++) {
        if (isPrime[i] && check(i)) {
            cout << i << "\n";
        }
    }
}
