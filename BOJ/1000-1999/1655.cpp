#include <iostream>
#include <queue>

using namespace std;

int N;
priority_queue<int, vector<int>, less<int>> max_pq;
priority_queue<int, vector<int>, greater<int>> min_pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    int x;
    for (int i=0; i<N; i++) {
        cin >> x;
        
        if (max_pq.empty() || x <= max_pq.top()) {
            max_pq.push(x);
        }
        else {
            min_pq.push(x);
        }
        
        while (max_pq.size() < i / 2 + 1) {
            max_pq.push(min_pq.top());
            min_pq.pop();
        }
        
        while (max_pq.size() > i / 2 + 1) {
            min_pq.push(max_pq.top());
            max_pq.pop();
        }
        
        cout << max_pq.top() << "\n";
    }

    return 0;
}
