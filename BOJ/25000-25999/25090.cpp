#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100001;
int T, N;
int arr[MAX];

void init_testcase() {
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    for (int t=1; t<=T; t++) {
        init_testcase();
        
        cin >> N;
        for (int i=0; i<N; i++) cin >> arr[i];
        
        sort(arr, arr+N);
        int l = 0;
        for (int i=0; i<N; i++) {
            if (arr[i] > l) l++;
        }
        
        cout << "Case #" << t << ": ";
        cout << l;
        cout << "\n";
    }

    return 0;
}
