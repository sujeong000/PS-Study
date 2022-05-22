#include <iostream>
#include <set>
#include <queue>

using namespace std;

typedef long long ll;

int K, N;
int prime[100];
set<ll> st;
priority_queue<ll, vector<ll>, greater<ll>> pq;

ll solution() {
    int cnt = 0;
    
    for (int i=0; i<N; i++) {
        ll curr = pq.top(); pq.pop();
        cnt++;
        if (cnt == N) return curr;
        
        for (int j=0; j<K; j++) {
            pq.push(curr * prime[j]);
            if (curr % prime[j] == 0) break;
        }
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> K >> N;
    for (int i=0; i<K; i++) {
        cin >> prime[i];
        pq.push(prime[i]);
    }
    
    cout << solution();
    
    return 0;
}
