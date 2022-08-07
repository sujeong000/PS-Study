#include <iostream>

using namespace std;

int H, W;
bool board[501][501];

int calcRain() {
    int sum = 0;
    
    for (int i=0; i<H; i++) {
        int last = -1;
        
        for (int j=0; j<W; j++) {
            if (board[i][j]) {
                if (last != -1) sum += j - last - 1;
                last = j;
            }
        }
    }
    
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> H >> W;
    
    for (int j=0; j<W; j++) {
        int h;
        cin >> h;
        
        for (int i=0; i<h; i++) {
            board[i][j] = true;
        }
    }
    
    cout << calcRain();

    return 0;
}
