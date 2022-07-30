#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int LIS(const vector<int>& arr) {
    vector<int> lis;
    
    lis.push_back(0);
    for (auto x: arr) {
        if (x > lis.back()) {
            lis.push_back(x);
        }
        else {
            int lb = lower_bound(lis.begin(), lis.end(), x) - lis.begin();
            lis[lb] = x;
        }
    }
    
    return lis.size() - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    
    while (cin >> N) {
        vector<int> v;
        
        for (int i=0; i<N; i++) {
            int x; cin >> x;
            v.push_back(x);
        }
        
        cout << LIS(v) << "\n";
    }

    return 0;
}
