#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

const int MAX = 40;
const int START = 0, END = 32, CENTER = 24, C1 = 5, C2 = 10, C3 = 15, C4 = 20;

int dice[10];
int cache[10][MAX][MAX][MAX][MAX];
int point[] = 
{
    0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40,
    13, 16, 19, 25, 22, 24, 28, 27, 26, 30, 35, 0
};

int move(int d, int start, int now) {
    if (now == END) return END;
    if (d == 0) return now;
    
    int next;
    switch (now) {
        case C1: next = (start == C1) ? 21 : now+1; break;
        case C2: next = (start == C2) ? 25 : now+1; break;
        case C3: next = (start == C3) ? 27 : now+1; break;
        case C4: next = END; break;
        case CENTER: next = 30; break;
        case 26: case 29: next = CENTER; break;
        case 31: next = C4; break;
        default: next = now+1; break;
    }
    
    return move(d-1, start, next);
}

bool check(int idx, vector<int> p) {
    for (int i=1; i<=3; i++) {
        int ap = p[(idx+i)%4];
        if (ap != END && ap == p[idx]) return false; 
    }
    
    return true;
}

int dp(int d, vector<int> p) {
    if (d == 10) return 0;
    
    int& ret = cache[d][p[0]][p[1]][p[2]][p[3]];
    if (ret != -1) return ret;
    
    ret = 0;
    
    for (int i=0; i<4; i++) {
        if (p[i] == END) continue;
                
        int new_pos = move(dice[d], p[i], p[i]);
        vector<int> newp = p;
        newp[i] = new_pos;
        if (!check(i, newp)) continue;

        ret = max(ret, point[new_pos] + dp(d+1, newp));
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    memset(cache, -1, sizeof(cache));
    
    for (int i=0; i<10; i++) cin >> dice[i];
    cout << dp(0, {0, 0, 0, 0});

    return 0;
}
