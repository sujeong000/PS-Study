#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<vector<ll>> Matrix;
const ll MOD = 1000000000;

ll A, B;
vector<vector<ll>> matrix =
{
    {1, 1, 1},
    {1, 0, 0},
    {0, 0, 1}
};

Matrix matrixMultiply(Matrix x, Matrix y) {
    int R = x.size(), C = y[0].size();
    Matrix ret = vector<vector<ll>>(R, vector<ll>(C, 0));
    
    for (int i=0; i<R; i++) {
        for (int j=0; j<C; j++) {
            for (int k=0; k<y.size(); k++) {
                ret[i][j] += (x[i][k] * y[k][j]) % MOD;
                ret[i][j] %= MOD;
            }
        }
    }
    
    return ret;
}

Matrix matrixPower(ll n) {
    if (n == 1) return matrix;
    
    Matrix half = matrixPower(n/2);
    if (n % 2 == 0) return matrixMultiply(half, half);
    else return matrixMultiply(matrix, matrixMultiply(half, half));
}

ll psum(ll n) {
    if (n <= 2) return n;
    
    Matrix res = matrixPower(n-2);
    return (2*res[0][0] + res[0][1] + res[0][2]) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> A >> B;
    cout << (psum(B) - psum(A-1) + MOD) % MOD;
}
