#include <iostream>
#include <vector>
#include <set>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

set<int> findM(vector<int>& A) {
    int M;
    vector<int> gap;
    set<int>ret;
    
    // 두 수 a, b를 M으로 나눈 나머지가 같다면
    // a = M*(a/M) + r
    // b = M*(b/M) + r
    // a-b = M*(a/M-b/M), (a-b)%M = 0
    for (int i=0; i<A.size()-1; i++) {
        gap.push_back(abs(A[i]-A[i+1]));
    }
    
    M = gap[0];
    for (int i=1; i<gap.size(); i++) {
        M = gcd(max(M, gap[i]), min(M, gap[i]));
    }
    
    ret.insert(M);
    for (int i=2; i*i<=M; i++) {
        if (M % i == 0) {
            ret.insert(i);
            ret.insert(M/i);
        }
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N;
    vector<int> A;
    set<int> ans;
    
    cin >> N;
    for (int i=0; i<N; i++) {
        int x; cin >> x;
        A.push_back(x);
    }
    
    ans = findM(A);
    for (auto x: ans) cout << x << "\n";

    return 0;
}
