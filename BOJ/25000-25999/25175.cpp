#include <iostream>

using namespace std;

int N, M, K;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> K;
    
    int next = (N + M-1 + K-3) % N + 1;
    if (K < 0) next = (N + next - 1) % N + 1;
    
    cout << next;

    return 0;
}
