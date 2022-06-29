#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

struct Segtree {
    int n;
    vector<ll> tree;
    
    Segtree (vector<ll>& X) {
        n = X.size();
        tree.resize(n*4);
        init(X, 0, n-1, 1);
    }
    
    void init(vector<ll>& X, int left, int right, int node) {
        if (left == right) {
            tree[node] = X[left];
            return;
        }
        
        int mid = (left + right) / 2;
        init(X, left, mid, node*2);
        init(X, mid+1, right, node*2+1);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
    
    ll query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if (left > nodeRight || right < nodeLeft) return 0;
        if (left <= nodeLeft && nodeRight <= right) return tree[node];
        
        int mid = (nodeLeft+nodeRight) / 2;
        ll l = query(left, right, node*2, nodeLeft, mid);
        ll r = query(left, right, node*2+1, mid+1, nodeRight);
        return l+r;
    }
    
    ll query(int left, int right) {
        return query(left, right, 1, 0, n-1);
    }
    
    void update(int idx, ll val, int node, int nodeLeft, int nodeRight) {
        if (idx < nodeLeft || idx > nodeRight) return;
        
        tree[node] += val;
        if (nodeLeft == nodeRight) return;
        
        int mid = (nodeLeft + nodeRight) / 2;
        update(idx, val, node*2, nodeLeft, mid);
        update(idx, val, node*2+1, mid+1, nodeRight);
    }
    
    void update(int idx, ll val) {
        update(idx, val, 1, 0, n-1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, Q; 
    cin >> N >> Q;
    
    vector<ll> A(N+1);
    Segtree st = Segtree(A);
    
    for (int i=0; i<Q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        
        if (a == 1) st.update(b, c);
        else cout << st.query(b, c) << "\n";
    }

    return 0;
}
