#include <string>
#include <vector>

using namespace std;

vector<vector<string>> allCases;

bool isEqual(char a, char b, char c) {
    return a == b && b == c;
}

bool isFinished(vector<string>& board) {
    // 세로
    for (int c=0; c<3; c++) {
        if (isEqual(board[0][c], board[1][c], board[2][c]) && board[0][c] != '.') {
            return true;
        }
    }
    // 가로
    for (int r=0; r<3; r++) {
        if (isEqual(board[r][0], board[r][1], board[r][2]) && board[r][0] != '.') {
            return true;
        }
    }
    // 대각선
    if (isEqual(board[0][0], board[1][1], board[2][2]) && board[1][1] != '.') {
        return true;
    }
    if (isEqual(board[0][2], board[1][1], board[2][0]) && board[1][1] != '.') {
        return true;
    }
    
    return false;
}

char nextTurn(char turn) {
    if (turn == 'O') return 'X';
    else return 'O';
}

bool isSameCase(vector<string>& case1, vector<string>& case2) {
    for (int i=0; i<3; i++) {
        if (case1[i] != case2[i]) return false;
    }
    
    return true;
}

void bruteforce(int cnt, char turn, vector<string> board) {
    allCases.push_back(board);
    
    if (cnt == 9 || isFinished(board)) return;
    
    for (int i=0; i<9; i++) {
        int r = i/3;
        int c = i%3;
        
        if (board[r][c] != '.') continue;
        
        board[r][c] = turn;
        bruteforce(cnt+1, nextTurn(turn), board);
        board[r][c] = '.';
    }
}

int solution(vector<string> board) {
    int answer = 0;
    
    // 모든 케이스 구하기
    bruteforce(0, 'O', {"...", "...", "..."});
    
    // 모든 케이스와 비교
    for (auto caseBoard: allCases) {
        if (isSameCase(caseBoard, board)) {
            answer = 1;
            break;
        }
    }
    
    return answer;
}
