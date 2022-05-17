#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, A, B;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    cin >> A >> B;
    
    A /= 2;
    
    cout << min(N, A+B);

    return 0;
}
