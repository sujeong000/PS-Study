// sol 1. 우선순위큐
#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int N;
priority_queue<piii, vector<piii>, greater<piii>> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i=0; i<N; i++) {
        int l, h, r;
        cin >> l >> h >> r;
        pq.push({l, {-h, r}});
    }
    
    vector<pii> ans;
    int curr_h = 0;
    int curr_l = 0;
    int curr_r = 0;
    
    while (!pq.empty()) {
        int l = pq.top().first;
        int h = -pq.top().second.first;
        int r = pq.top().second.second;
        pq.pop();
        
        if (curr_r < l) {
            if (curr_r != 0) ans.push_back({curr_r, 0});
            ans.push_back({l, h});
            curr_h = h;
            curr_l = l;
            curr_r = r;
        }
        else if (curr_r == l) {
            if (h == curr_h) {
                curr_r = max(curr_r, r);
            }
            else {
                ans.push_back({l, h});
                curr_h = h;
                curr_l = l;
                curr_r = r;
            }
        }
        else {
            if (h > curr_h) {
                ans.push_back({l, h});
                // 더 높은 건물에 포함되는 부분만 잘라내기
                if (curr_r > r) pq.push({r, {-curr_h, curr_r}});
                curr_h = h;
                curr_l = l;
                curr_r = r;
            }
            else if (h == curr_h) {
                curr_r = max(curr_r, r);
            }
            else {
                // 더 높은 건물에 포함되는 부분만 잘라내기
                if (r > curr_r) pq.push({curr_r, {-h, r}});
            }
        }
    }
    
    ans.push_back({curr_r, 0});
    
    for (auto pos: ans) {
        cout << pos.first << " " << pos.second << " ";
    }

    return 0;
}

// sol 2. map/set
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    vector<piii> v;
    for (int i=0; i<N; i++) {
        int l, h, r;
        cin >> l >> h >> r;
        v.push_back({l, {0, -h}});
        v.push_back({r, {1, h}});
    }
    
    sort(v.begin(), v.end());
    
    vector<pii> ans;
    map<int, int> mp;
    for (auto pos: v) {
        int x = pos.first;
        int t = pos.second.first;
        int h = t == 0 ? -pos.second.second : pos.second.second;
        
        // 시작점 or 끝 점에서만 높이가 변한다
        if (t == 0) {   // 시작점
            // 새 빌딩 or 더 높은 빌딩
            if (mp.empty() || mp.rbegin()->first < h) ans.push_back({x, h});
            mp[h]++;
        }
        else {          // 끝점
            int max_h = mp.rbegin()->first;
            mp[h]--;
            if (mp[h] == 0) mp.erase(h);
            
            // 없어지면 땅 or 더 낮은 빌딩
            if (mp.empty()) ans.push_back({x, 0});
            else if (max_h != mp.rbegin()->first) ans.push_back({x, mp.rbegin()->first});
        }
    }
    
    for (auto pos: ans) {
        cout << pos.first << " " << pos.second << " ";
    }

    return 0;
}
