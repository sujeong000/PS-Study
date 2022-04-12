#include <iostream>
#include <cmath>

using namespace std;

int S, N, K, R1, R2, C1, C2;
bool res[51][51];

// 원래 보드에서 (sr, sc)를 왼쪽 꼭짓점으로하고 크기가 sz x sz인 부분 채우기
void fill(int sz, int sr, int sc) {
    if (sz == 1) return;
    if (sr > R2 || sc > C2 || sr+sz-1 < R1 || sc+sz-1 < C1) return;
    
    // 가운데 K조각을 검정색으로 채우기
    int black_s = sz/N * (N-K)/2;
    int black_e = black_s + sz/N*K - 1;
    int black_r1 = max(R1, black_s+sr);
    int black_c1 = max(C1, black_s+sc);
    int black_r2 = min(R2, black_e+sr);
    int black_c2 = min(C2, black_e+sc);
    for (int i=black_r1; i<=black_r2; i++) {
        for (int j=black_c1; j<=black_c2; j++) {
            res[i-R1][j-C1] = true;
        }
    }
    
    // 남은 부분 재귀적으로 색칠
    for (int i=0; i<sz; i+=sz/N) {
        for (int j=0; j<sz; j+=sz/N) {
            fill(sz/N, sr+i, sc+j);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> S >> N >> K >> R1 >> R2 >> C1 >> C2;
    
    fill((int)pow(N, S), 0, 0);
    
    for (int i=0; i<R2-R1+1; i++) {
        for (int j=0; j<C2-C1+1; j++) {
            cout << (res[i][j] ? 1 : 0);
        }
        cout << "\n";
    }

    return 0;
}
