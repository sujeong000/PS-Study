#include <iostream>

using namespace std;

int N;
char arr[2000][2000];
bool no_bomb[2000][2000];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};

void explode(int r, int c) {
    for(int i=0; i<4; i++) {
        int next_r = r + dr[i];
        int next_c = c + dc[i];
        
        while (next_r >= 0 && next_r < N && next_c >= 0 && next_c < N) {
            if (arr[next_r][next_c] != '.') break;
            
            no_bomb[next_r][next_c] = true; // 상하좌우에 O가 있으면 폭탄터지면 안됨
            
            next_r += dr[i];
            next_c += dc[i];
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if (arr[i][j] != 'O') continue;
            
            explode(i, j);
        }
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if (arr[i][j] != '.') cout << arr[i][j];
            else {
                if (no_bomb[i][j]) cout << ".";
                else cout << "B";
            }
        }
        cout << "\n";
    }

    return 0;
}
