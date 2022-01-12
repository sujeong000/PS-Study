#include <iostream>

using namespace std;

int n, x;
int tree[100001];
int dict[100001];

int sum(int pos) {
    int ret = 0;
    while (pos > 0) {
        ret += tree[pos];
        pos &= (pos - 1);
    }

    return ret;
}

void add(int pos, int val) {
    while (pos < n + 1) {
        tree[pos] += val;
        pos += (pos & -pos);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int testcase;
    cin >> testcase;

    for (int t = 1; t <= testcase; t++) {
        for (int i = 0; i < 100001; i++) {
            tree[i] = 0;
        }
        
        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> x;
            dict[x] = i + 1;
        }

        long long result = 0;
        for (int i = 0; i < n; i++) {
            cin >> x;
            
            int index = dict[x];
            if (index != n) {
                result += sum(n - index);
            }
            add(n + 1 - index, 1);
        }
        
        cout << result << "\n";
    }

    return 0;
}
