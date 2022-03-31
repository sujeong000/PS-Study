#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int N, M;
int crane[51], box[10001];
map<int, int> mp;

int solution() {
    int minute = 0;
    
    while (!mp.empty()) {
        if (crane[N-1] < mp.begin()->first) return -1;
        
        minute++;
        for (int i=0; i<N; i++) {
            // 옮길 수 있는 박스 중 가장 무거운 박스를 옮긴다.
            auto ub = mp.upper_bound(crane[i]);
            if (ub == mp.begin()) continue;
            
            ub--;
            if (ub->second == 1) mp.erase(ub->first);
            else mp[ub->first]--;
        }
    }
    
    return minute;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i=0; i<N; i++) cin >> crane[i];
    cin >> M;
    for (int i=0; i<M; i++) {
        cin >> box[i];
        if (mp.find(box[i]) == mp.end()) mp[box[i]] = 1;
        else mp[box[i]]++;
    }
    
    sort(crane, crane+N);
    
    cout << solution();

    return 0;
}
