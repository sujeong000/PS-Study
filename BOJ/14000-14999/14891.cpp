#include <iostream>

using namespace std;

const int N = 4, M = 8, NINE = 6, THREE = 2, CCW = -1, CW = 1;

int K;
int gear[N][M];
int start[N];    // 12시 방향의 인덱스

void rotate(int idx, int d) {
    if (d == CCW) {
        start[idx] = (start[idx] + 1) % M;
    } else {
        start[idx] = (start[idx] + M - 1) % M;
    }
}

void transfer(int from, int to, int d) {
    if (to < 0 || to >= N) return;
    
    if (from < to) {    // 좌 -> 우
        int l = gear[from][(THREE + start[from]) % M];
        int r = gear[to][(NINE + start[to]) % M];
            
        if (l != r) {
            transfer(to, to+1, -d); // 우측으로 전이
            rotate(to, -d);
        }
    } else {            // 우 -> 좌
        int l = gear[to][(THREE + start[to]) % M];
        int r = gear[from][(NINE + start[from]) % M];
        
        if (l != r) {
            transfer(to, to-1, -d); // 좌측으로 전이
            rotate(to, -d);
        }
    }
}

void simulate(int idx, int d) {
    transfer(idx, idx-1, d);
    transfer(idx, idx+1, d);
    rotate(idx, d);
}

int calc_score() {
    int ret = 0;
    
    for (int i=0; i<N; i++) {
        if (gear[i][start[i]]) {
            ret += (1 << i);
        }
    }
    
    return ret;
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL); cout.tie(NULL);
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            scanf("%1d", &gear[i][j]);   
        }
    }
    
    cin >> K;
    
    int idx, d;
    
    for (int i=0; i<K; i++) {
        cin >> idx >> d;
        simulate(idx-1, d);
    }
    
    cout << calc_score();

    return 0;
}
