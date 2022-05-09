#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100001;

int N;
int A[MAX];
vector<int> v;

int lower_bound(int x) {
    int lo = 0, hi = v.size();
    
    while (lo < hi) {
        int mid = (lo+hi) / 2;
        if (v[mid] < x) lo = mid+1;
        else hi = mid;
    }
    
    return lo;
}

int LIS() {
    v.push_back(0);
    
    for (int i=0; i<N; i++) {
        if (v.back() < A[i]) {
            v.push_back(A[i]);
        }
        else {
            int lb = lower_bound(A[i]);
            v[lb] = A[i];
        }
    }
    
    return v.size() - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i=0; i<N; i++) cin >> A[i];
    
    cout << N - LIS();

    return 0;
}
