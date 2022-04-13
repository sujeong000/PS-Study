#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int N;
string num;
ll cnt[10];
bool front[10];
vector<pll> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> num;
        
        front[num[0] - 'A'] = true;
        for (int j=0; j<num.size(); j++) {
            int alpha = num[j] - 'A';
            cnt[alpha] += pow(10, num.size()-j-1);
        }
    }
    
    // 많이 등장하는 순으로 정렬
    for (int i=0; i<10; i++) {
        if (cnt[i] == 0) continue;
        v.push_back({cnt[i], i});
    }
    sort(v.begin(), v.end(), greater<pll>());
    
    // 0으로 시작하는 수가 없도록
    if (v.size() == 10) {
        for (int i=9; i>=0; i--) {
            if (!front[v[i].second]) {
                pll zero = v[i];
                v.erase(v.begin()+i);
                v.push_back(zero);
                break;
            }
        }
    }
    
    ll ans = 0;
    for (int i=0; i<v.size(); i++) ans += v[i].first * (9 - i);
    cout << ans;

    return 0;
}
