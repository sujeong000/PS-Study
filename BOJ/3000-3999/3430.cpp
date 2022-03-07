#include <iostream>
#include <string.h>

using namespace std;

const int MAX = 1000001;
int N, M;
int rain[MAX], tree[MAX];
int last[MAX];      // last[i] = i번째 호수에 마지막으로 비내린 날
int drink[MAX];     // drink[i] = i번째 날에 용이 물을 마신 호수

int sum(int to) {
    if (to == 0) return 0;
    
    int pos = to;
    int ret = 0;
    
    while (pos > 0) {
        ret += tree[pos];
        pos &= (pos - 1);
    }
    
    return ret;
}

int sum(int from, int to) {
    return sum(to) - sum(from - 1);
}

void update(int at, int val) {
    int pos = at;
    
    while (pos < MAX) {
        tree[pos] += val;
        pos += (pos & -pos);
    }
}

int lower_bound(int s, int target) {
    int lo = s, hi = M;
    
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (sum(s, mid) < target) lo = mid + 1;
        else hi = mid;
    }
    
    return lo;
}

bool simulate() {
    for (int i=1; i<=M; i++) {
        int lake = rain[i];
        
        if (!lake) {
            update(i, 1);
        }
        else {
            int lb = lower_bound(last[lake], 1);
            
            // 마지막으로 비가 온 날 이후로 비가 안온 날이 적어도 한번은 있어야 한다.
            if (lb >= i) {  
                return false;
            }
            else {
                update(lb, -1);
                drink[lb] = lake;
                last[lake] = i;
            }
        }
    }
    
    return true;
}

void init_testcase() {
    memset(tree, 0, sizeof(tree));
    memset(last, 0, sizeof(last));
    memset(drink, 0, sizeof(drink));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        init_testcase();
        
        cin >> N >> M;
        
        for (int i=1; i<=M; i++) cin >> rain[i];
        
        if (simulate()) {
            cout << "YES\n";
            for (int i=1; i<=M; i++) {
                if (!rain[i]) cout << drink[i] << " ";
            }
            cout << "\n";
        }
        else {
            cout << "NO\n";
        }
    }

    return 0;
}
