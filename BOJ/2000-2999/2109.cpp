#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N;
vector<int> lectures[10001];

int optimize() {
    int ret = 0;
    priority_queue<int> pq;
    
    for (int day=10000; day>0; day--) {
        for (auto lecture: lectures[day]) pq.push(lecture);
        if (!pq.empty()) {
            ret += pq.top();
            pq.pop();
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
        int p, d;
        cin >> p >> d;
        
        lectures[d].push_back(p);
    }
    
    cout << optimize();
    
    return 0;
}
