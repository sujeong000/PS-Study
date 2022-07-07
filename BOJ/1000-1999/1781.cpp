#include <iostream>
#include <queue>

using namespace std;

const int MAX = 200001;

int N;
vector<int> problems[MAX];

int optimize() {
    int ret = 0;
    priority_queue<int, vector<int>, less<int>> pq;
    
    // 시간 역순으로 가장 많은 컵라면을 받을 수 있는 문제를 고른다.
    for (int day=N; day>=1; day--) {
        for (auto p: problems[day]) pq.push(p);
        if (!pq.empty()) {
            ret += pq.top(); pq.pop();
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i=0; i<N; i++) {
        int deadLine, ramen;
        cin >> deadLine >> ramen;
        
        problems[deadLine].push_back(ramen);
    }
    
    cout << optimize();

    return 0;
}
