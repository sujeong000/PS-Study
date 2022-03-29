#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int N;
vector<ll> arr;

ll make_decreasing_num(int mask) {
    ll ret = 0;
    
    // 큰 수부터 차례로 나열하면 감소하는 수가 완성된다.
    for (int i=9; i>=0; i--) {
        if ((mask & (1 << i)) != 0) {
            ret *= 10;
            ret += i;
        }
    }
    
    return ret;
}

void find_all_decreasing_nums() {
    // 0-9 중 사용할 수들을 선택하면 감소하는 수가 결정된다.
    for (int i=1; i<(1 << 10); i++) {
        arr.push_back(make_decreasing_num(i));
    }
}

ll nth_decreasing_num(int x) {
    find_all_decreasing_nums();
    sort(arr.begin(), arr.end());
    
    if (arr.size() <= x) return -1;
    else return arr[x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    cout << nth_decreasing_num(N);

    return 0;
}
