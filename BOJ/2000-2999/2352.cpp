#include <iostream>
#include <vector>

using namespace std;

const int MAX = 40001;

int N;
int match[MAX];
vector<int> v;

int lower_bound(int x) {
    int lo = 0, hi = v.size();
    
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (v[mid] < x) lo = mid + 1;
        else hi = mid;
    }
    
    return lo;
}

int LIS() {
    v.push_back(0);
    
    for (int i=1; i<=N; i++) {
        if (match[i] > v.back()) {
            v.push_back(match[i]);
        }
        else {
            int lb = lower_bound(match[i]);
            v[lb] = match[i];
        }
    }
    
    return v.size() - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i=1; i<=N; i++) cin >> match[i];
    
    cout << LIS();
    
    return 0;
}
