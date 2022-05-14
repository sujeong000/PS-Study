#include <iostream>

using namespace std;

int S, M;

bool coogie_help() {
    int SS = S - 1023;
    
    for (int i=0; i<10; i++) {
        if ((M & (1 << i)) == 0) continue;
        SS &= ~(1 << i);
    }
    
    return SS == 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> S >> M;
    
    if (S < 1024) cout << "No thanks";
    else if (coogie_help()) cout << "Thanks";
    else cout << "Impossible";

    return 0;
}
