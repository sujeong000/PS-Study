#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

struct Segtree {
    int n;
    vector<ll> tree;
    
    Segtree(const vector<ll>& A) {
        n = A.size();
        tree.resize(n*4);
        init(A, 0, n-1, 1);
    }
    
    void init(const vector<ll>& A, int left, int right, int node) {
        if (left == right) {
            tree[node] = A[left];
            return;
        }
        
        int mid = (left+right)/2;
        init(A, left, mid, node*2);
        init(A, mid+1, right, node*2+1);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
    
    void update(int pos, int node, int nodeLeft, int nodeRight, ll diff) {
        if (pos < nodeLeft || pos > nodeRight) return;
        
        tree[node] += diff;
        if (nodeLeft == nodeRight) return;
        
        int mid = (nodeLeft+nodeRight)/2;
        update(pos, node*2, nodeLeft, mid, diff);
        update(pos, node*2+1, mid+1, nodeRight, diff);
    }
    
    void update(int pos, ll diff) {
        update(pos, 1, 0, n-1, diff);
    }
    
    ll query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if (nodeLeft > right || nodeRight < left) return 0;
        if (left <= nodeLeft && nodeRight <= right) return tree[node];
        
        int mid = (nodeLeft+nodeRight)/2;
        ll lsum = query(left, right, node*2, nodeLeft, mid);
        ll rsum = query(left, right, node*2+1, mid+1, nodeRight);
        return lsum + rsum;
    }
    
    ll query(int left, int right) {
        return query(left, right, 1, 0, n-1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M;
    ll a, b, c;
    vector<ll> A;
    
    cin >> N;
    A.resize(N);
    
    Segtree ST(A);
    
    cin >> M;
    for (int i=0; i<M; i++) {
        cin >> a >> b >> c;
        if (a == 0) {
            if (b > c) swap(b, c);
            cout << ST.query(b-1, c-1) << "\n";
        }
        else {
            ST.update(b-1, c-A[b-1]);
            A[b-1] = c;
        }
    }

    return 0;
}
