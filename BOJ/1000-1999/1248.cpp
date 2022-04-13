#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

int N;
string s;
char matrix[11][11];
int pick[11];
int psum[11][11];
bool solved;

bool validate(int idx) {
    for (int j=0; j<=idx; j++) {
        if (matrix[j][idx] == '+' && psum[j][idx] <= 0) return false;
        if (matrix[j][idx] == '-' && psum[j][idx] >= 0) return false;
        if (matrix[j][idx] == 0 && psum[j][idx] != 0) return false;
    }
    
    return true;
}

void brute_force(int idx) {
    if (solved) return;
    if (idx == N) {
        for (int i=0; i<N; i++) cout << pick[i] << " ";
        solved = true;
        return;
    }
    
    int sign;
    if (matrix[idx][idx] == '-') sign = -1;
    else if (matrix[idx][idx] == '+') sign = 1;
    else sign = 0;
    
    for (int i=1; i<=10; i++) {
        int val = i * sign;
        
        pick[idx] = val;
        for (int j=0; j<=idx; j++) {
            if (idx == 0) psum[j][idx] = val;
            else psum[j][idx] = psum[j][idx-1] + val;
        }
        
        if (validate(idx)) brute_force(idx+1);
        if (solved || sign == 0) return;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    cin >> s;
    int idx = 0;
    for (int i=0; i<N; i++) {
        for (int j=i; j<N; j++) {
            matrix[i][j] = s[idx++];
        }
    }
    
    brute_force(0);

    return 0;
}
