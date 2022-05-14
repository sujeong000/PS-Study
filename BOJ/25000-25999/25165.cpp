#include <iostream>

using namespace std;

int N, M, Ac, D, Sr, Sc;

bool check() {
    if (Sr == 1) {
        if (D == 0 && Sc <= M) return true;
        else if (D == 1 && Sc >= M) return true;
        else return false;
    }
    else if (Sr == N) {
        if (N % 2 != 0) return D != 0;
        else return D == 0;
    }
    else return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    cin >> Ac >> D;
    cin >> Sr >> Sc;
    
    if (check()) cout << "NO...";
    else cout << "YES!";

    return 0;
}
