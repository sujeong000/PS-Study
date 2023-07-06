#include <iostream>
#include <vector>

using namespace std;

const int INF = 8;

// 세 mbti의 심리적 거리를 구하는 함수
int calcDist(string a, string b, string c) {
    int diff = 4;
    
    for (int i=0; i<4; i++) {
        if (a[i] == b[i] && b[i] == c[i]) diff--;
    }
    
    // 세 명이 일치하지 않는 타입 하나마다 거리가 2씩 증가하므로
    return 2 * diff;
}

int calcMinDist(vector<string>& mbtis) {
    int min_dist = INF;
    int n = (int)mbtis.size();
    
    if (n > 32) {
        // Pigeonhole Principle에 의해
        // (16*2 + 1)명의 사람을 16개의 mbti로 분류하는 경우,
        // 최소한 한 mbti에는 반드시 3명이상 속하게 된다.
        min_dist = 0;
    }
    else {
        for (int i=0; i<n-2; i++) {
            for (int j=i+1; j<n-1; j++) {
                for (int k=j+1; k<n; k++) {
                    int dist = calcDist(mbtis[i], mbtis[j], mbtis[k]);
                    min_dist = min(min_dist, dist);
                }
            }
        }
    }
    
    return min_dist;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        vector<string> mbtis(N);
        for (int i=0; i<N; i++) cin >> mbtis[i];
        
        cout << calcMinDist(mbtis) << "\n";
    }
}
