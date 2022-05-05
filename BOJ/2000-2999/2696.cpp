#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int T, M;
priority_queue<int, vector<int>, greater<int>> minq;
priority_queue<int, vector<int>, less<int>> maxq;
vector<int> ans;

void init_testcase() {
    ans.clear();
    while (!minq.empty()) minq.pop();
    while (!maxq.empty()) maxq.pop();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    while (T--) {
        init_testcase();
        
        cin >> M;
        
        int x;
        for (int i=0; i<M; i++) {
            cin >> x;
            
            // maxq에는 정렬 결과의 앞쪽 저장
            // minq에는 정렬 결과의 뒷쪽 저장
            if (!minq.empty() && minq.top() < x) minq.push(x);
            else maxq.push(x);
            
            while (maxq.size() > i/2+1) {
                minq.push(maxq.top());
                maxq.pop();
            }
            while (maxq.size() < i/2+1) {
                maxq.push(minq.top());
                minq.pop();
            }
            
            if (i % 2 == 0) ans.push_back(maxq.top());
        }
        
        cout << ans.size() << "\n";
        for (int i=0; i<ans.size(); i++) {
            if (i > 9 && i % 10 == 0) cout << "\n";
            cout << ans[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
