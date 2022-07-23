#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int N, M, K;
pii students[200001];

bool refereeCompare(const pii& lhs, const pii& rhs) {
    return lhs.second > rhs.second;
}

bool organizerCompare(const pii& lhs, const pii& rhs) {
    return lhs.first > rhs.first;
}

ll pick() {
    ll sum = 0;
    
    // 심판 점수를 기준으로 1~K등은 무조건 뽑힌다
    sort(students, students+N, refereeCompare);
    for (int i=0; i<K; i++) sum += students[i].first;
    
    // 남은 학생들 중 주최자 점수 기준 상위 M명을 뽑는다
    sort(students+K, students+N, organizerCompare);
    for (int i=K; i<K+M; i++) sum += students[i].first;
    
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> K;
    for (int i=0; i<N; i++) {
        int a, b; cin >> a >> b;
        students[i] = {a, b};
    }
    
    cout << pick();
    
    return 0;
}
