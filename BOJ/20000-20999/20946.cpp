#include <iostream>
#include <queue>
#include <cmath>

using namespace std;

long long N;
queue<long long> q; // 소인수들

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    long long i = 2;
    long long original_N = N;
    
    while (i <= N && i <= sqrt(original_N)) {
        if (N % i == 0) {
            q.push(i);
            N /= i;
        }
        else {
            if (i == 2) i++;
            else i += 2;
        }
    }
    
    if (N > 2) q.push(N);   // 이런 경우 뭐지?
    
    if (q.size() <= 1) cout << -1;
    else {
        if (q.size() % 2 == 0) {
            while (!q.empty()) {
                long long a = q.front(); q.pop();
                long long b = q.front(); q.pop();
                cout << a * b << " ";
            }
        }
        else {
            while (q.size() > 3) {
                long long a = q.front(); q.pop();
                long long b = q.front(); q.pop();
                cout << a * b << " ";
            }
            
            long long a = q.front(); q.pop();
            long long b = q.front(); q.pop();
            long long c = q.front(); q.pop();
            cout << a*b*c;
        }
    }
    
    return 0;
}
