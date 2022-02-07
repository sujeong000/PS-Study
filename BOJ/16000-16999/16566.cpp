#include <iostream>

using namespace std;

int N, M, K;
int tree[4000001];

int sum(int to) {
    if (to == 0) return 0;
    
    int ret = 0;
    int pos = to;
    
    while (pos > 0) {
        ret += tree[pos];
        pos &= (pos - 1);
    }
    
    return ret;
}

void add(int at, int val) {
    int pos = at;
    
    while (pos < 4000001) {
        tree[pos] += val;
        pos += (pos & -pos);
    }
}

int lower_bound(int x) {
    int lo = x + 1, hi = N;
    
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        int val = sum(mid) - sum(x);
        
        if (val < 1) lo = mid + 1;
        else hi = mid;
    }
    
    return lo;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> K;
    
    int card;
    
    for (int i = 0; i < M; i++) {
        cin >> card;
        add(card, 1);
    }
    
    int red_card;
    
    for (int i = 0; i < K; i++) {
        cin >> red_card;
        int blue_card = lower_bound(red_card);
        add(blue_card, -1);
        
        cout << blue_card << "\n";
    }

    return 0;
}
