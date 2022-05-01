#include <iostream>

using namespace std;

int T, R, C;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> R >> C;
        
        cout << "Case #" << t << ":\n";
        for (int i=0; i<2*R+1; i++) {
            for (int j=0; j<2*C+1; j++) {
                if (i <= 1 && j <= 1) {
                    cout << ".";
                    continue;
                }
                
                if (i % 2 == 0) {
                    if (j % 2) cout << "-";
                    else cout << "+";
                }
                else {
                    if (j % 2) cout << ".";
                    else cout << "|";
                }
            }
            cout << "\n";
        }
    }

    return 0;
}
