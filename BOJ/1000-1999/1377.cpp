#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 500001;
typedef pair<int, int> pii;

int N;
pii arr[MAX];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    int x;
    for (int i=0; i<N; i++) {
        cin >> x;
        arr[i] = {x, i};
    }
    
    sort(arr, arr+N);
    
    // 제자리로 가기 위해서는 arr[i].second - i만큼 왼쪽으로 이동해야함
    int max_val = 0;
    for (int i=0; i<N; i++) max_val = max(max_val, arr[i].second-i);
    cout << max_val + 1;

    return 0;
}
