#include <iostream>

using namespace std;

int N;
int cnt[9];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    while (N > 0) {
        int x = N % 10;
        N /= 10;
        
        if (x == 9) cnt[6]++;
        else cnt[x]++;
    }
    
    cnt[6] = (cnt[6]+1) / 2;
    
    int max_cnt = 0;
    for (int i=0; i<9; i++) max_cnt = max(max_cnt, cnt[i]);
    
    cout << max_cnt;

    return 0;
}
