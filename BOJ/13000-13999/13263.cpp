#include <iostream>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAX = 100'001;

struct Function {
    ll a, b;
};

int n, top = -1;
int A[MAX], B[MAX];
Function funcs[MAX];
ll dp[MAX];

// 두 함수의 교점 계산
ld intersect(Function s1, Function s2) {
    return (ld)(s1.b - s2.b) / (s2.a - s1.a);
}

// idx번 함수 필터링하여 추가
void addFunction(Function func) {
    while (top >= 1 && intersect(funcs[top], funcs[top-1]) > intersect(funcs[top], func)) {
        top--;
    }
    funcs[++top] = func;
}

// 찾는 함수가 idx번 함수 이후에 있는가
bool decision(int idx, int x) {
    ld ix = intersect(funcs[idx], funcs[idx+1]);
    return x >= ix;
}

// f(x)를 최소로 만드는 함수 찾기
Function optimize(int x) {
    int lo = 0, hi = top;
    
    while (lo < hi) {
        int mid = (lo+hi)/2;
        if (decision(mid, x)) lo = mid+1;
        else hi = mid;
    }
    
    return funcs[lo];
}

int main()
{
    cin >> n;
    for (int i=0; i<n; i++) cin >> A[i];
    for (int i=0; i<n; i++) cin >> B[i];
    
    // dp[i]: i번 나무를 높이 1까지 자르는 최소 비용
    // dp[i] = min(dp[j] + a[i]*b[j])
    for (int i=1; i<n; i++) {
        addFunction({B[i-1], dp[i-1]});
        Function f = optimize(A[i]);
        dp[i] = f.a * A[i] + f.b;
    }
    
    cout << dp[n-1];

    return 0;
}
