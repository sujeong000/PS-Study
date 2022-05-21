#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

const int MAX = 100001, BEFORE = 0, AFTER = 1;

int N, M;
int rows[MAX][2], cols[MAX][2];

bool parity_check() {
    for (int i=1; i<MAX; i++) {
        rows[i][BEFORE] %= 2;
        rows[i][AFTER] %= 2;
        cols[i][BEFORE] %= 2;
        cols[i][AFTER] %= 2;
        
        if (rows[i][BEFORE] != rows[i][AFTER]) return false;
        if (cols[i][BEFORE] != cols[i][AFTER]) return false;
    }
    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    int x, y;
    for (int i=0; i<N; i++) {
        cin >> x >> y;
        rows[x][BEFORE]++;
        cols[y][BEFORE]++;
    }
    for (int i=0; i<M; i++) {
        cin >> x >> y;
        rows[x][AFTER]++;
        cols[y][AFTER]++;
    }
    
    if (parity_check()) cout << "YES";
    else cout << "NO";

    return 0;
}
