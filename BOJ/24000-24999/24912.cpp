#include <iostream>
#include <string.h>

using namespace std;

int N;
int colors[1000002];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;    
    for (int i=1; i<=N; i++) cin >> colors[i];
    
    for (int i=1; i<N; i++) {
        if (colors[i] != 0 && colors[i] == colors[i+1]) {
            cout << -1;
            return 0;
        }
    }

    for (int i=1; i<=N; i++) {
        if (colors[i] != 0) continue;
        
        for (int c=1; c<=3; c++) {
            if (colors[i-1] == c || colors[i+1] == c) continue;
            
            colors[i] = c;
            break;
        }
    }
    
    for (int i=1; i<=N; i++) cout << colors[i] << " ";
    
    return 0;
}
