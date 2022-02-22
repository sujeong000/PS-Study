#include <iostream>
#include <algorithm>

using namespace std;

int N;
int arr[5000], d[5000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    for(int i=0; i<N; i++) cin >> arr[i];
    
    sort(arr, arr+N);

    int max_d = 0;
    
    for(int i=0; i<N; i++) {
        d[i] = 1;
        
        for(int j=0; j<i; j++) {
            if (arr[i] % arr[j] == 0) {
                d[i] = max(d[i], d[j] + 1);
            }
        }
        
        max_d = max(max_d, d[i]);
    }
    
    cout << N - max_d;

    return 0;
}
