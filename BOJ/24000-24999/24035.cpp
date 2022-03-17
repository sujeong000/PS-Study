#include <iostream>
#include <algorithm>

using namespace std;

int arr[101];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    
    cin >> T;
    
    for (int t=1; t<=T; t++) {
        int N;
        
        cin >> N;
        
        for (int i=0; i<N; i++) {
            cin >> arr[i];
        }
        
        sort(arr, arr+N);
        
        int sum = 0;
        int cnt = 0;
        
        for (int i=0; i<N; i++) {
            if (i == 0 || arr[i] != arr[i-1]) cnt++;
            sum += cnt;
        }
        
        cout << "Case #" << t << ": " << sum << "\n";
    }

    return 0;
}
