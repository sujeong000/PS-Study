#include <iostream>
#include <string.h>

using namespace std;

const int MAX = 10001;
const int MIN = -987654321;

int X;
int num[4], cache[4][MAX], sol[4];
int cost[] = {1, 5, 10, 25};

int dp(int idx, int x) {
    if (idx == 4) {
        if (x == 0) return 0;
        else return MIN;
    }
    
    int& ret = cache[idx][x];
    if (ret != -1) return ret;
    
    ret = MIN;
    for (int i=0; i<=num[idx]; i++) {
        int new_x = x - i*cost[idx];
        if (new_x < 0) break;
        ret = max(ret, i + dp(idx+1, new_x));
    }
    
    return ret;
}

void back_track(int idx, int x) {
    if (idx == 4) return;
    
    int ret = MIN;
    for (int i=0; i<=num[idx]; i++) {
        int new_x = x - i*cost[idx];
        if (new_x < 0) break;
        
        int res = i + dp(idx+1, new_x);
        if (res >= 0 && ret < res) {
            sol[idx] = i;
            ret = res;
        }
    }
    
    if (ret <= 0) return;
    back_track(idx+1, x-sol[idx]*cost[idx]);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    cin >> X;
    for (int i=0; i<4; i++) cin >> num[i];
    
    back_track(0, X);
    
    for (int i=0; i<4; i++) cout << sol[i] << " ";

    return 0;
}
