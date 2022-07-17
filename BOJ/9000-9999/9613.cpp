#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int N;
int arr[100];

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

ll calcGCDSum() {
    ll sum = 0;
    
    sort(arr, arr+N);
    
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            sum += gcd(arr[j], arr[i]);
        }
    }
    
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    while (T--) {
        cin >> N;
        for (int i=0; i<N; i++) cin >> arr[i];
        
        cout << calcGCDSum() << "\n";
    }
    
    return 0;
}
