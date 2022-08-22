#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int N;
vector<int> assignments[1001];

int optimize() {
    int sum = 0;
    priority_queue<int> pq;
    
    // 시간 역순으로 가장 점수를 많이 받을 수 있는 과제를 고른다.
    for (int day=1000; day>0; day--) {
        for (auto x: assignments[day]) pq.push(x);
        if (!pq.empty()) {
            sum += pq.top(); pq.pop();
        }
    }
    
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    for (int i=0; i<N; i++) {
        int d, w;
        cin >> d >> w;
        
        assignments[d].push_back(w);
    }
    
    cout << optimize();
    
    return 0;
}
