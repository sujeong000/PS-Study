#include <iostream>
#include <vector>

using namespace std;

bool check(vector<int>& A) {
    int N = A.size();
    
    for (int i=0; i<N; i++) {
        int minCand = min(A[i], N-A[i]+1);
        int maxCand = max(A[i], N-A[i]+1);
        
        if (i == 0) A[i] = minCand;
        else {
            if (minCand < A[i-1]) {
                if (maxCand < A[i-1]) return false;
                else A[i] = maxCand;
            }
            else A[i] = minCand;
        }
    }
    
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        
        vector<int> A(N, 0);
        for (int i=0; i<N; i++) cin >> A[i];
        
        if (check(A)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
