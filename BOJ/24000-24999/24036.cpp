#include <iostream>
#include <vector>

using namespace std;

int L[100];
char arr[2501];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    
    cin >> T;
    
    for (int t=1; t<=T; t++) {
        int N;
        
        cin >> N;
        
        for (int i=0; i<N; i++) cin >> L[i];
        
        int cnt = 0;
        
        // 짝수 블록: 뒤부터 ABC..
        // 홀수 블록: 앞부터 BCD.. 마지막은 다음 블록의 첫글자+1
        for (int i=0; i<N; i++) {
            for (int j=0; j<L[i]; j++, cnt++) {
                arr[cnt] = (i % 2 == 0) ? 'A'+(j+1) : 'A'+L[i]-(j+1);
            }
            
            if (i % 2 != 0) {
                arr[cnt-L[i]-1] = max((int)arr[cnt-L[i]-1], 'A'+L[i]);
            }
        }
        
        cout << "Case #" << t << ": A";
        for (int i=0; i<cnt; i++) cout << arr[i];
        cout << "\n";
    }

    return 0;
}
