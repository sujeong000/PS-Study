#include <iostream>
#include <set>

using namespace std;
typedef long long ll;

int N, M;
ll A[300001];
bool arithmetic[300001];    // A[i-1]~A[i+1]이 양의 등차수열인가
bool geometric[300001];     // A[i-1]~A[i+1]이 양의 등비수열인가
int arithmeticCnt, geometricCnt;

bool isArithmetic(int i) {
    if (i == 1) {
        return A[i+1]-A[i] > 0;
    }
    else if (i == N) {
        return A[i]-A[i-1] > 0;
    }
    else {
        return A[i]-A[i-1] == A[i+1]-A[i] && 
               A[i]-A[i-1] > 0;
    }
}

bool isGeometric(int i) {
    if (i == 1) {
        return A[i+1] % A[i] == 0 && 
               A[i+1] >= A[i];
    }
    else if (i == N) {
        return A[i] % A[i-1] == 0 && 
               A[i] >= A[i-1];
    }
    else {
        return A[i+1] % A[i] == 0 && 
               A[i] % A[i-1] == 0 && 
               A[i+1]/A[i] == A[i]/A[i-1] &&
               A[i+1] >= A[i];
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    for (int i=1; i<=N; i++) cin >> A[i];
    for (int i=1; i<=N; i++) {
        arithmetic[i] = isArithmetic(i);
        if (arithmetic[i]) arithmeticCnt++;
        
        geometric[i] = isGeometric(i);
        if (geometric[i]) geometricCnt++;
    }
    
    for (int m=0; m<M; m++) {
        ll x, y;
        cin >> x >> y;
        
        ll originalValue = A[x];
        
        for (int i=-1; i<=1; i++) {
            int idx = x+i;
            if (idx < 1 || idx > N) continue;
            
            bool arithmeticBefore = arithmetic[idx];
            bool geometricBefore = geometric[idx];
            
            A[x] = y;
            
            arithmetic[idx] = isArithmetic(idx);
            geometric[idx] = isGeometric(idx);
            
            bool arithmeticAfter = arithmetic[idx];
            bool geometricAfter = geometric[idx];
            
            if (!arithmeticBefore && arithmeticAfter) arithmeticCnt++;
            if (arithmeticBefore && !arithmeticAfter) arithmeticCnt--;
            if (!geometricBefore && geometricAfter) geometricCnt++;
            if (geometricBefore && !geometricAfter) geometricCnt--;
            
            A[x] = originalValue;
        }
        
        // 진짜 바꾸기
        A[x] = y;
        
        if (arithmeticCnt == N) cout << "+";
        else if (geometricCnt == N) cout << "*";
        else cout << "?";
        cout << "\n";
    }
    
    return 0;
}
