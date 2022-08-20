#include <iostream>
#include <queue>

using namespace std;
const int INF = 987654321;

bool isPrime[10000];

int changeDigit(int n, int base, int to) {
    int ret = n;
    
    ret -= (n / base % 10) * base;
    ret += base * to;
    
    return ret;
}

int BFS(int from, int to) {
    vector<int> visit(10000, INF);
    queue<int> q;
    
    visit[from] = 0;
    q.push(from);
    
    while (!q.empty()) {
        int curr = q.front(); q.pop();
               
        for (int base=1; base<=1000; base*=10) {
            for (int i=0; i<=9; i++) {
                int next = changeDigit(curr, base, i);
                        
                if (next < 1000) continue;
                if (!isPrime[next]) continue;
                if (visit[next] != INF) continue;

                visit[next] = visit[curr] + 1;
                q.push(next);
            }
        }
    }
    
    return visit[to];
}

void calcPrimes() {
    for (int i=2; i<10000; i++) {
        isPrime[i] = true;
    }
    
    for (int i=2; i<10000; i++) {
        if (!isPrime[i]) continue;
        
        int temp = i*2;
        while (temp < 10000) {
            isPrime[temp] = false;
            temp += i;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    calcPrimes();
    
    int T; cin >> T;
    while (T--) {
        int A, B;
        cin >> A >> B;
        
        int ans = BFS(A, B);
        
        if (ans == INF) cout << "Impossible" << "\n";
        else cout << ans << "\n";
    }

    return 0;
}

