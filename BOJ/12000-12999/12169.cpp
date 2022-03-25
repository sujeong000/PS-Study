#include <iostream>
#include <string.h>

using namespace std;

int T, D, P;
int cnt[1001];

int solution(int d) {
    int ret = 1001;

    // 총 i번의 노말 턴을 진행하는 경우 시뮬레이션
    // 모든 경우의 수 시도 i=1~1000
    for (int i=1; i<=1000; i++) {
        // 노말 턴보다 스페셜 턴을 먼저 진행하는게 항상 이득이다.
        // 스페셜턴을 먼저 진행해야 노말 때 소진되는 팬케이크 수가 더 많아짐
        // 따라서 스페셜 턴을 먼저 다 진행한 후 노말턴 진행
        
        int special_cnt = 0;
        
        for (int p=1; p<=1000; p++) {
            // i번의 노말턴으로 끝내려면 전부 i이하여야 한다.
            // (p-1)/i = p개의 팬케이크를 i개 이하의 여러 묶음으로 나누기 위해 필요한 스페셜 턴 수
            special_cnt += cnt[p] * ((p - 1) / i);
        }
        
        ret = min(ret, special_cnt + i);
    }
    
    return ret;
}

void init_testcase() {
    memset(cnt, 0, sizeof(cnt));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    
    for (int t=1; t<=T; t++) {
        init_testcase();
        
        cin >> D;
        
        for (int i=0; i<D; i++) {
            cin >> P;
            cnt[P]++;
        }
        
        int ans = solution(D);
        
        cout << "Case #" << t << ": " << ans << "\n";
    }

    return 0;
}
