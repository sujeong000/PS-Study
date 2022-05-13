#include <iostream>
#include <string>

using namespace std;

typedef long long ll;

int T, N, K;
ll arr[1001];

string solution() {
    ll p = 0, q = arr[N-1];
    
    for (int i=0; i<N-1; i++) {
        q += arr[i];
        
        for (int j=i+1; j<N; j++) {
            p += arr[i] * arr[j];
        }
    }
    
    if (K == 1) {
        if (q == 0) {
            return p == 0 ? "0" : "IMPOSSIBLE";
        }
        else {
            return p % q == 0 ? to_string(-p/q) : "IMPOSSIBLE";
        }   
    }
    else {
        ll n1 = 1-q;
        ll n2 = -(p + n1*q);
        return to_string(n1) + " " + to_string(n2);
    }
}

void init_testcase() {
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    for (int t=1; t<=T; t++) {
        init_testcase();
        
        cin >> N >> K;
        for (int i=0; i<N; i++) cin >> arr[i];
        
        cout << "Case #" << t << ": ";
        cout << solution();
        cout << "\n";
    }

    return 0;
}
