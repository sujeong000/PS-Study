#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    string S; cin >> S;
    
    for (int i=0; i<N; i++) cout << S;

    return 0;
}
