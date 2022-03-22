#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    
    for (int t=1; t<=T; t++) {
        int N;
        string B;
        
        cin >> N >> B;
        cout << "Case #" << t << ": ";
        
        for (int i=0; i<N; i++) {
            int b = 0;
            
            for (int j=0; j<8; j++) {
                b *= 2;
                if (B[i*8+j] == 'I') b += 1;
            }
            
            cout << (char)b;
        }
        
        cout << "\n";
    }

    return 0;
}
