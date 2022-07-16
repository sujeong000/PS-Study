#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int arr[10000];

int findMaximum() {
    sort(arr, arr+N);
    
    for (int i=0; i<N; i++) {
        int avg = M / (N-i);

        if (arr[i] < avg) M -= arr[i];
        else return avg;
    }
    
    return arr[N-1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i=0; i<N; i++) cin >> arr[i];
    cin >> M;
    
    cout << findMaximum();

    return 0;
}
