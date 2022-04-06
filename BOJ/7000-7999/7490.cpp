#include <iostream>
#include <string.h>

using namespace std;

typedef long long ll;

int T, N;
int pick[10];

bool check() {
    int val = 0, i = 1;
    
    while (i <= N) {
        int s = i;
        int num = i++;
        while (i <= N && pick[i] == 0) {
            num = num * 10 + i++;
        }
        
        if (pick[s] > 0) val += num;
        else val -= num;
    }
    
    return val == 0;
}

void print_exp() {
    cout << 1;
    
    for (int i=2; i<=N; i++) {
        if (pick[i] > 0) cout << "+";
        else if (pick[i] < 0) cout << "-";
        else cout << " ";
        
        cout << i;
    }
    
    cout << "\n";
}

void dfs(int idx) {
    if (idx > N) {
        if (check()) print_exp();
        return;
    }
    
    pick[idx] = 0; dfs(idx+1);
    pick[idx] = 1; dfs(idx+1);
    pick[idx] = -1; dfs(idx+1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    while (T--) {
        cin >> N;
        pick[1] = 1;
        dfs(2);
        cout << "\n";
    }

    return 0;
}
