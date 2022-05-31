#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

struct Segtree {
    int n;
    vector<ll> negative, zero;
    vector<ll> A;
    
    Segtree (vector<ll>& X) {
        A = X;
        n = A.size();
        negative.resize(n*4);
        zero.resize(n*4);
        init(0, n-1, 1);
    }
    
    void init(int left, int right, int node) {
        if (left == right) {
            negative[node] = (A[left] < 0) ? 1 : 0;
            zero[node] = (A[left] == 0) ? 1 : 0;
            return;
        }
        
        int mid = (left+right)/2;
        init(left, mid, node*2);
        init(mid+1, right, node*2+1);
        negative[node] = negative[node*2] + negative[node*2+1];
        zero[node] = zero[node*2] + zero[node*2+1];
    }
    
    ll query(int left, int right, int node, int nodeLeft, int nodeRight, bool zeroSum) {
        if (nodeRight < left || nodeLeft > right) return 0;
        if (left <= nodeLeft && nodeRight <= right) {
            if (zeroSum) return zero[node];
            else return negative[node];
        }
        
        int mid = (nodeLeft+nodeRight)/2;
        ll l = query(left, right, node*2, nodeLeft, mid, zeroSum);
        ll r = query(left, right, node*2+1, mid+1, nodeRight, zeroSum);
        return l+r;
    }
    
    char query(int left, int right) {
        ll negativeCnt = query(left, right, 1, 0, n-1, false);
        ll zeroCnt = query(left, right, 1, 0, n-1, true);
        
        if (zeroCnt > 0) return '0';
        else return (negativeCnt % 2) ? '-' : '+';
    }
    
    void update(int idx, ll val, int node, int nodeLeft, int nodeRight) {
        if (idx < nodeLeft || idx > nodeRight) return;
        
        if (A[idx] == 0 && val != 0) zero[node]--;
        else if (A[idx] != 0 && val == 0) zero[node]++;
        if (A[idx] < 0 && val >= 0) negative[node]--;
        else if (A[idx] >= 0 && val < 0) negative[node]++;
        
        if (nodeLeft == nodeRight) return;
        
        int mid = (nodeLeft+nodeRight)/2;
        update(idx, val, node*2, nodeLeft, mid);
        update(idx, val, node*2+1, mid+1, nodeRight);
    }
    
    void update(int idx, ll val) {
        update(idx, val, 1, 0, n-1);
        A[idx] = val;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, K;
    
    while (cin >> N >> K) {
        vector<ll> X(N);
        for (int i=0; i<N; i++) cin >> X[i];
        
        Segtree ST(X);
        
        char t;
        ll a, b;
        for (int i=0; i<K; i++) {
            cin >> t >> a >> b;
            if (t == 'C') ST.update(a-1, b);
            else cout << ST.query(a-1, b-1);
        }
        cout << "\n";
    }
    
    return 0;
}
