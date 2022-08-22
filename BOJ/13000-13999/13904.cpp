#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int N;
priority_queue<pii> arr;    // 마감일 내림차순
priority_queue<pii> pq;     // 점수 내림차순

int optimize() {
    int sum = 0;
    
    // 미래부터 과제 정하기
    for (int day=1000; day>0; day--) {
        // 마감일이 day 이상인 과제 전부 pq에 넣기
        while (!arr.empty() && arr.top().first >= day) {
            pii temp = arr.top(); arr.pop();
            swap(temp.first, temp.second);
            pq.push(temp);
        }
        
        // 가능한 과제 중 가장 점수 높은 과제 수행
        if (!pq.empty()) {
            sum += pq.top().first;
            pq.pop();   
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
        
        arr.push({d, w});
    }
    
    cout << optimize();
    
    return 0;
}
