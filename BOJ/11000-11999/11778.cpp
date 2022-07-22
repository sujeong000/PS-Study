#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> Matrix;
const ll MOD = 1000000007;

ll N, M;
Matrix A = {{1, 1}, {1, 0}};

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

Matrix matrixMultiply(Matrix a, Matrix b) {
    int R = a.size();
    int C = b[0].size();
    int K = b.size();
    Matrix ret = Matrix(R, vector<ll>(C, 0));
    
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            for (int k=0; k<K; k++) {
                ret[i][j] += (a[i][k] * b[k][j]) % MOD;
                ret[i][j] %= MOD;
            }
        }
    }
    
    return ret;
}

Matrix matrixPower(Matrix m, ll n) {
    if (n == 1) return m;
    
    Matrix half = matrixPower(m, n/2);
    if (n % 2 == 0) return matrixMultiply(half, half);
    else return matrixMultiply(matrixMultiply(half, half), m);
}

ll fibonacci(ll n) {
    if (n == 1) return 1;
    else return matrixPower(A, n-1)[0][0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    if (N > M) swap(N, M);
    
    // gcd(f(m), f(n)) = f(gcd(m, n));
    cout << fibonacci(gcd(N, M));

    return 0;
}
