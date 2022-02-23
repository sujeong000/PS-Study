#include <iostream>

using namespace std;

int N;
int cnt[50001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    int x;
    int max_cnt = 0;
    
    for(int i=0; i<N; i++) {
        cin >> x;
        
        cnt[x]++;
        max_cnt = max(max_cnt, cnt[x]);
    }
    
    cout << max_cnt;
    
    return 0;
}
