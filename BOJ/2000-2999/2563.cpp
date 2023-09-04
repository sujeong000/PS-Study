#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100;
const int SIZE_OF_PAPER = 10;

int N;
bool board[MAX][MAX];

int countNumberOfGrid() {
    int ret = 0;
    
    for (int i=0; i<MAX; i++) {
        for (int j=0; j<MAX; j++) {
            if (board[i][j]) ret++;
        }
    }
    
    return ret;
}

void addPaper(int hlo, int vlo) {
    int hhi = hlo + SIZE_OF_PAPER;
    int vhi = vlo + SIZE_OF_PAPER;
    
    for (int r=vlo; r<vhi; r++) {
        for (int c=hlo; c<hhi; c++) {
            // 그리드 (r,c)에 색종이가 붙어있음
            board[r][c] = true;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for (int i=0; i<N; i++) {
        int hlo, vlo;
        cin >> hlo >> vlo;
        addPaper(hlo, vlo);
    }

    cout << countNumberOfGrid();
    
    return 0;
}
