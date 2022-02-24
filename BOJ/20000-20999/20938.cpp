#include <iostream>

using namespace std;

int N, K;
long double p[2501];
long double pmul[2501][2501];   // pmul[i][j] = p[i]~p[j]까지 (1-p)의 곱
long double ev[2501][2501];     // ev[i][j] = i~j까지 한 묶음일때 기댓값
long double cache[2501][11];

// dp(idx, k) = idx번째~마지막전구까지를 최대 K묶음으로 잘랐을 때 켜진 전구수의 최대 기댓값
long double dp(int idx, int k) {
    if (idx == N) return 0;
    
    long double& ret = cache[idx][k];
    if (ret != -1) return ret;
    
    if (k == 1) ret = ev[idx][N-1];
    else {
        ret = 0;
        
        for(int hi = idx; hi < N; hi++) {   // idx-hi까지 한묶음으로 하고 자른다.
            ret = max(ret, ev[idx][hi] + dp(hi+1, k-1));
        }
    }
    
    return ret;
}

void calc_pmul() {
    for(int i=0; i<N; i++) {
        pmul[i][i] = 1 - p[i];
        
        for(int j=i+1; j<N; j++) {
            pmul[i][j] = pmul[i][j-1] * (1 - p[j]);
        }
    }
}

void calc_ev() {
    for(int i=0; i<N; i++) {
        ev[i][i] = pmul[i][i];
        
        for(int j=i+1; j<N; j++) {
            ev[i][j] = ev[i][j-1] + pmul[i][j];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for(int i=0; i<2501; i++) {
        for(int j=0; j<11; j++) {
            cache[i][j] = -1;
        }
    }
    
    cin >> N >> K;
    
    for(int i=0; i<N; i++) cin >> p[i];
    
    calc_pmul();
    calc_ev();
    
    cout << fixed;
    cout.precision(10);
    
    cout << dp(0, K);

    return 0;
}
