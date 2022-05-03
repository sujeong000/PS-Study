#include <iostream>

using namespace std;

int N, M;
int pick[7];

void brute_force(int cnt) {
    if (cnt == M) {
        for (int i=0; i<M; i++) cout << pick[i] << " ";
        cout << "\n";
        return;
    }
    
    for (int i=1; i<=N; i++) {
        pick[cnt] = i;
        brute_force(cnt+1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    
    brute_force(0);
    
    return 0;
}
