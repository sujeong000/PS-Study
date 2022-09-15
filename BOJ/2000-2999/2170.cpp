#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

int N;
vector<pii> lines;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i=0; i<N; i++) {
        int s, e;
        cin >> s >> e;
        lines.push_back({s, e});
    }
    
    sort(lines.begin(), lines.end());
    
    int len = lines[0].second - lines[0].first;
    int e = lines[0].second;    // 제일 끝 점
    
    for (int i=1; i<N; i++) {
        if (lines[i].second <= e) continue;
        
        if (e > lines[i].first) {
            len += lines[i].second - e;
        }
        else {
            len += lines[i].second - lines[i].first;
        }
        
        e = max(e, lines[i].second);
    }
    
    cout << len;

    return 0;
}
