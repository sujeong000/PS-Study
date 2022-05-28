#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

struct Segtree {
    int n;
    vector<ll> tree, lazy;
     
    Segtree(const vector<ll>& A) {
        n = A.size();
        tree.resize(n*4);
        lazy.resize(n*4);
        init(A, 0, n-1, 1);
    }
    
    void init(const vector<ll>& A, int left, int right, int node) {
        if (left == right) {
            tree[node] = A[left];
            return;
        }
        
        int mid = (left+right) / 2;
        init(A, left, mid, node*2);
        init(A, mid+1, right, node*2+1);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
    
    void update_lazy(int left, int right, int node) {
        if (lazy[node] == 0) return;
        
        // 켜진 전구가 tree[node]개라면 반전 후에는 (right-left+1) - tree[node]개가 켜져있음
        tree[node] = (right-left+1) - tree[node];
        if (left != right) {
            lazy[node*2] = !lazy[node*2];
            lazy[node*2+1] = !lazy[node*2+1];
        }
        lazy[node] = 0;
    }
    
    void update_range(int left, int right, int node, int nodeLeft, int nodeRight, ll val) {
        update_lazy(nodeLeft, nodeRight, node);
        
        if (right < nodeLeft || nodeRight < left) return;
        if (left <= nodeLeft && nodeRight <= right) {
            tree[node] = (nodeRight-nodeLeft+1) - tree[node];
            if (nodeLeft != nodeRight) {
                lazy[node*2] = !lazy[node*2];
                lazy[node*2+1] = !lazy[node*2+1];
            }
            return;
        }
        
        int mid = (nodeLeft+nodeRight)/2;
        update_range(left, right, node*2, nodeLeft, mid, val);
        update_range(left, right, node*2+1, mid+1, nodeRight, val);
        tree[node] = tree[node*2] + tree[node*2+1];
    }
    
    void update_range(int left, int right, ll val) {
        update_range(left, right, 1, 0, n-1, val);
    }
    
    ll query(int left, int right, int node, int nodeLeft, int nodeRight) {
        update_lazy(nodeLeft, nodeRight, node);
        
        if (right < nodeLeft || nodeRight < left) return 0;
        if (left <= nodeLeft && nodeRight <= right) return tree[node];
        
        int mid = (nodeLeft+nodeRight) / 2;
        ll leftSum = query(left, right, node*2, nodeLeft, mid);
        ll rightSum = query(left, right, node*2+1, mid+1, nodeRight);
        return leftSum + rightSum;
    }
    
    ll query(int left, int right) {
        return query(left, right, 1, 0, n-1);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, M, O, S, T;
    
    cin >> N >> M;
    
    vector<ll> A(N, 0);
    Segtree ST(A);
    
    for (int i=0; i<M; i++) {
        cin >> O >> S >> T;
        if (O == 0) {
            ST.update_range(S-1, T-1, 1);
        }
        else {
            cout << ST.query(S-1, T-1) << "\n";
        }
    }

    return 0;
}
