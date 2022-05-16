#include <iostream>

using namespace std;

typedef long long ll;
const int MAX = 100001;

int N, Q;
ll arr[MAX], tree[MAX];

ll sum(int pos) {
    ll ret = 0;
    
    while (pos > 0) {
        ret += tree[pos];
        pos &= (pos - 1);
    }
    
    return ret;
}

void add(int pos, ll val) {
    while (pos < MAX) {
        tree[pos] += val;
        pos += (pos & -pos);
    }
}

ll sum(int s, int e) {
    return sum(e) - sum(s-1);
}

void update(int idx, ll val) {
    add(idx, val - arr[idx]);
    arr[idx] = val;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> Q;
    for (int i=1; i<=N; i++) {
        cin >> arr[i];
        add(i, arr[i]);
    }
    
    int x, y, a, b;
    for (int i=0; i<Q; i++) {
        cin >> x >> y >> a >> b;
        if (x > y) swap(x, y);
        
        cout << sum(x, y) << "\n";
        update(a, b);
    }

    return 0;
}
