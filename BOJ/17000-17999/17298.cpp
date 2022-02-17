#include <iostream>
#include <stack>

using namespace std;

int N;
int arr[1000001];
int NGE[1000001];
stack<int> s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    
    for(int i=1; i<=N; i++) {
        cin >> arr[i];
    }
    
    for(int i=N; i>=1; i--) {
        while (!s.empty() && s.top() <= arr[i]) s.pop();
        
        if (s.empty()) {
            NGE[i] = -1;
        }
        else {
            NGE[i] = s.top();
        }
        
        s.push(arr[i]);
    }
    
    for(int i=1; i<=N; i++) {
        cout << NGE[i] << " ";
    }

    return 0;
}
