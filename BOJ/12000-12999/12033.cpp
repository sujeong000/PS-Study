#include <iostream>

using namespace std;

int N;
int arr[201];

void find(int s, int x) {
    for (int i=s; i<2*N; i++) {
        if (arr[i] == x) {
            arr[i] = -1;
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    
    for (int t=1; t<=T; t++) {
        cin >> N;
        
        for (int i=0; i<2*N; i++) cin >> arr[i];
        
        cout << "Case #" << t << ": ";
        
        for (int i=0; i<2*N; i++) {
            if (arr[i] == -1) continue;
            
            find(i+1, arr[i]/3*4);
            cout << arr[i] << " ";
        }
        
        cout << "\n";
    }

    return 0;
}
