#include <iostream>
#include <limits.h>

using namespace std;

int N;
int max_result = INT_MIN;
char mexp[19];

int calc(int a, char op, int b) {
    switch (op) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
    }
    
    return 0;
}

void brute_force(int idx, int val) {
    if (idx >= N) {
        max_result = max(max_result, val);
        return;
    }
    
    // 1. 괄호 안하는 경우
    char op = mexp[idx];
    int a = mexp[idx+1] - '0';
    
    brute_force(idx+2, calc(val, op, a));
    
    if (idx > N-4) return;
    
    // 2. 괄호 하는 경우
    char op2 = mexp[idx+2];
    int b = mexp[idx+3] - '0';
    int c = calc(a, op2, b);
    
    brute_force(idx+4, calc(val, op, c));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    
    for(int i=0; i<N; i++) {
        cin >> mexp[i];
    }
    
    if (N == 1) max_result = mexp[0] - '0';
    else brute_force(1, mexp[0]-'0');
    
    cout << max_result;

    return 0;
}
