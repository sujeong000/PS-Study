#include <iostream>

using namespace std;

int N;

int factorial(int n) {
    if (n == 1) return 1;
    return n * factorial(n-1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    cout << factorial(N);

    return 0;
}
