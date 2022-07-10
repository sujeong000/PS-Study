#include <iostream>
#include <stack>

using namespace std;

const int MAX = 1000001;

int N;
int A[MAX], F[MAX], NFG[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    for (int i=0; i<N; i++) {
        cin >> A[i];
        F[A[i]]++;
    }
    
    stack<int> s;
    
    for (int i=N-1; i>=0; i--) {
        while (!s.empty() && F[s.top()] <= F[A[i]]) s.pop();
        
        if (s.empty()) NFG[i] = -1;
        else NFG[i] = s.top();
        
        s.push(A[i]);
    }
    
    for (int i=0; i<N; i++) cout << NFG[i] << " ";
    
    return 0;
}
