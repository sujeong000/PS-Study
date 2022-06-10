#include <iostream>

using namespace std;
typedef long double ld;

int check(int h, int w) {
    if (h < 140.1) return 6;
    if (h < 146) return 5;
    if (h < 159) return 4;
    if (h < 161) {
        if (10000*w < 16*h*h || 10000*w >= 35*h*h) return 4;
        else return 3;
    }
    if (h < 204) {
        if (10000*w < 16*h*h || 10000*w >= 35*h*h) return 4;
        if (100000*w < 185*h*h || 10000*w >= 30*h*h) return 3;
        if (10000*w < 20*h*h || 10000*w >= 25*h*h) return 2;
        else return 1;
    }
    return 4;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T; cin >> T;
    for (int i=0; i<T; i++) {
        int h, w;
        cin >> h >> w;
        cout << check(h, w) << "\n";
    }

    return 0;
}
