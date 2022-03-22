#include <iostream>
#include <cmath>

using namespace std;

int multifactorial[9000];

int calc_multifactorial(int n) {
    double ret = 0;
    
    for (int i=9000; i>=1; i-=n)
        ret += log10(i);
    
    return (int)ret + 1;
}

void fill_multifactorial() {
    for (int i=1; i<9000; i++) {
        multifactorial[i] = calc_multifactorial(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    fill_multifactorial();
    
    int T;
    cin >> T;
    
    for (int t=1; t<=T; t++) {
        int D;
        cin >> D;
        
        int ans = 0;
        
        for (int i=1; i<9000; i++) {
            if (D > multifactorial[i]) {
                ans = i;
                break;
            }
        }
        
        cout << "Case #" << t << ": ";
        
        if (ans == 0) cout << "...";
        else {
            cout << "IT'S OVER 9000";
            for (int i=0; i<ans; i++) cout << "!";
        }
        
        cout << "\n";
    }

    return 0;
}
