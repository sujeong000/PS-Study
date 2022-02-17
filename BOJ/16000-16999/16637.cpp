#include <iostream>
#include <limits.h>

using namespace std;

int N;
int max_result = INT_MIN;
char mexp[19];

void brute_force(int idx, int val) {
    if (idx >= N) {
        max_result = max(max_result, val);
        return;
    }
    
    // 1. 괄호 안하는 경우
    char op = mexp[idx];
    int a = mexp[idx+1] - '0';
    
    switch (op) {
        case '+':
            brute_force(idx+2, val+a);
            break;
        case '-':
            brute_force(idx+2, val-a);
            break;
        case '*':
            brute_force(idx+2, val*a);
            break;
        default:
            break;
    }
    
    // 2. 괄호 하는 경우
    if (idx > N-4) return;
    
    char op2 = mexp[idx+2];
    int b = mexp[idx+3] - '0';
    
    switch (op2) {
        case '+':
            a = a + b;
            break;
        case '-':
            a  = a - b;
            break;
        case '*':
            a = a * b;
            break;
        default:
            break;
    }
    
    switch (op) {
        case '+':
            brute_force(idx+4, val+a);
            break;
        case '-':
            brute_force(idx+4, val-a);
            break;
        case '*':
            brute_force(idx+4, val*a);
            break;
        default:
            break;
    }
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
