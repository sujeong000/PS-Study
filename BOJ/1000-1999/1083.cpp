#include <iostream>

using namespace std;

int N, S;
int A[51];

int main()
{
    cin >> N;
    for (int i=0; i<N; i++) cin >> A[i];
    cin >> S;
    
    int start = 0;
    while (start < N && S > 0) {
        // S번 이내의 스왑으로 끌어올 수 있는 가장 큰 값을 A[start]로 끌어오기
        int maxIdx = start;
        
        for (int i=start; i<=min(N-1, start+S); i++) {
            if (A[maxIdx] < A[i]) maxIdx = i;
        }
        for (int i=maxIdx; i>start; i--) {
            swap(A[i], A[i-1]);
            S--;
        }
        
        start++;
    }
    
    for (int i=0; i<N; i++) cout << A[i] << " ";

    return 0;
}
