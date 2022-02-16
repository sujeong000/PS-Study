#include <iostream>
#include <vector>

using namespace std;

int MOD = 1000000007;
int N, M, K;
int arr[1000001];
vector<long long> tree(1000001, 1);
vector<int> zero_tree(1000001);

long long pow(int x, int n) {
    if (n == 1) return x;
    
    long long half = pow(x, n/2);
    
    if (n % 2 == 0) return half * half % MOD;
    else return (half * half % MOD) * x % MOD;
}

long long moduloInverse(int x) {
    return pow(x, MOD-2);
}

long long pmul(int pos) {
    if (pos == 0) return 1;
    
    long long ret = 1;
    
    while (pos > 0) {
        ret = ret * tree[pos] % MOD;
        pos &= (pos - 1);
    }
    
    return ret;
}

void multiply(int pos, int val) {
    while (pos < tree.size()) {
        tree[pos] = tree[pos] * val % MOD;
        pos += (pos & -pos);
    }
}

int psum(int pos) {
    if (pos == 0) return 0;
    
    int ret = 0; 
    
    while (pos > 0) {
        ret += zero_tree[pos];
        pos &= (pos - 1);
    }
    
    return ret;
}

void add(int pos, int val) {
    while (pos < zero_tree.size()) {
        zero_tree[pos] += val;
        pos += (pos & -pos);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> K;

    for(int i=1; i<=N; i++) {
        cin >> arr[i];
        
        if (arr[i] == 0) {
            add(i, 1);
            arr[i] = 1;
        }
        else {
            multiply(i, arr[i]);
        }
    }
    
    int a, b, c;
    
    for(int i=0; i<M+K; i++) {
        cin >> a >> b >> c;
        
        if (a == 1) {
            if (c == 0) {
                add(b, 1);
            }
            else {
                if (psum(b) - psum(b-1) > 0) add(b, -1);
                multiply(b, moduloInverse(arr[b]));
                multiply(b, c);
                arr[b] = c; 
            }
        }
        else {
            if (psum(c) - psum(b-1) > 0) cout << 0 << "\n";
            else cout << pmul(c) * moduloInverse(pmul(b-1)) % MOD << "\n";
        }
    }

    return 0;
}
