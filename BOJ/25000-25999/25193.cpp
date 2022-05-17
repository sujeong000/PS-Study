#include <iostream>
#include <set>

using namespace std;

int N;
string S;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> S;
    
    int chicken = 0;
    for (int i=0; i<N; i++) {
        if (S[i] == 'C') chicken++;
    }
    
    int ans = chicken / (N-chicken+1);
    if (chicken % (N-chicken+1) != 0) ans++;
    
    cout << ans;
    
    return 0;
}
