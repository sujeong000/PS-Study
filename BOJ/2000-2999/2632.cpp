#include <iostream>
#include <map>

using namespace std;
typedef long long ll;

int P, M, N;
int A[1001], B[1001];
int sumA[1001][1001], sumB[1001][1001];     // sum[i][j] = i번 조각부터 j번 조각까지 구간합
map<int, int> mp;       // mp[i] = B피자로 연속합 i를 만드는 가짓수

void calcSum() {
    for (int s=0; s<M; s++) {
        for (int i=0; i<M; i++) {
            int e = (s+i)%M;
            sumA[s][e] = sumA[s][(e-1+M)%M] + A[e];
        }
    }
    
    for (int s=0; s<N; s++) {
        for (int i=0; i<N; i++) {
            int e = (s+i)%N;
            sumB[s][e] = sumB[s][(e-1+N)%N] + B[e];
        }
    }
}

ll solution() {
    ll ret = 0;
    
    calcSum();
    
    for (int s=0; s<N; s++) {
        for (int i=0; i<N-1; i++) { // 전체 선택 중복 제거
            int e = (s+i)%N;
            mp[sumB[s][e]]++;
        }
    }
    mp[0] = 1;
    mp[sumB[0][N-1]]++;
    ret += mp[P];
    
    for (int s=0; s<M; s++) {
        for (int i=0; i<M-1; i++) { // 전체 선택 중복 제거
            int e = (s+i)%M;
            ret += mp[P-sumA[s][e]];
        }
    }
    ret += mp[P-sumA[0][M-1]];
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> P;
    cin >> M >> N;
    for (int i=0; i<M; i++) cin >> A[i];
    for (int i=0; i<N; i++) cin >> B[i];
    
    cout << solution();
    
    return 0;
}
