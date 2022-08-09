#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

string a0, a1;
int N;
Matrix X = {{0, 0}, {1, 0}};

Matrix multiply(Matrix a, Matrix b) {
    Matrix ret = Matrix(2, vector<int>(2, 0));
    
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            for (int k=0; k<2; k++) {
                ret[i][j] += (a[i][k] * b[k][j]) % 100;
                ret[i][j] %= 100;
            }
        }
    }
    
    return ret;
}

Matrix power(Matrix m, int n) {
    if (n == 1) return m;
    
    Matrix half = power(m, n/2);
    if (n % 2 == 0) return multiply(half, half);
    else return multiply(m, multiply(half, half));
}

int toInt(string s) {
    return (s[0] - '0') * 10 + (s[1] - '0');
}

int A(int n) {
    if (n == 0) return toInt(a0);
    if (n == 1) return toInt(a1);
    
    Matrix ans = power(X, N-1);
    return (ans[0][0] * toInt(a1) + ans[0][1] * toInt(a0)) % 100;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> X[0][0] >> X[0][1] >> a0 >> a1 >> N;
    
    int ans = A(N);
    cout << ans / 10;
    cout << ans % 10;

    return 0;
}
