#include <iostream>

using namespace std;

typedef long long ll;

int N, M, K;
bool lamp[51][51];

// fill_nth_row(n): n번째 행을 켰을 때 켜져있는 행의 수
int fill_nth_row(int n) {
    ll state = 0;
    int cnt = 0;
    
    for (int j=0; j<M; j++) {
        if (!lamp[n][j]) cnt++;
    }
    
    // K번 눌러서 n번째 행을 켤 수 없는 경우
    if ((cnt > K) || ((K-cnt) % 2 != 0)) return 0;
    
    // 켜진 행의 수 카운트
    int ret = 0;
    for (int i=0; i<N; i++) {
        bool on = true;
        
        for (int j=0; j<M; j++) {
            if (lamp[n][j] != lamp[i][j]) {
                on = false;
                break;
            }
        }
        
        if (on) ret++;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    for (int i=0; i<N; i++) {
        string s;
        cin >> s;
        for (int j=0; j<M; j++) lamp[i][j] = (s[j] == '1');
    }
    
    cin >> K;
    
    int max_row = 0;
    for (int i=0; i<N; i++) max_row = max(max_row, fill_nth_row(i));
    
    cout << max_row;

    return 0;
}
