#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;

int score, tile_cnt;
vector<vector<int>> green(6, vector<int>(4));
vector<vector<int>> blue(6, vector<int>(4));

vector<pii> getBlocks(int t, int x, int y) {
    vector<pii> ret;
    
    ret.push_back({x, y});
    if (t == 2) ret.push_back({x, y+1});
    else if (t == 3) ret.push_back({x+1, y});
    
    return ret;
}

vector<pii> toBlueBlocks(vector<pii> green_blocks) {
    vector<pii> ret;
    
    for (auto block: green_blocks) {
        ret.push_back({block.second, block.first});
    }
    
    return ret;
}

pii simulateGravity(pii block, vector<vector<int>>& board) {
    int r = 0;
    int c = block.second;
    while (r+1<6 && !board[r+1][c]) r++;
    
    return {r, c};
}

void applyGravity(vector<pii> blocks, vector<vector<int>>& board) {
    int min_gap = 987654321;
    
    for (auto block: blocks) {
        auto new_block = simulateGravity(block, board);
        min_gap = min(min_gap, new_block.first - block.first);
    }
    
    for (auto block: blocks) {
        int r = block.first;
        int c = block.second;
        board[r+min_gap][c] = true;
    }
}

void popRow(vector<vector<int>>& board) {
    for (int i=2; i<6; i++) {
        bool filled_row = true;
        
        for (int j=0; j<4; j++) {
            if (!board[i][j]) {
                filled_row = false;
                break;
            }
        }
        
        if (filled_row) {
            score++;    // 1점 획득
            // 아래로 이동
            for (int r=i-1; r>=0; r--) {
                for (int c=0; c<4; c++) {
                    board[r+1][c] = board[r][c];
                    board[r][c] = false;
                }
            }
        }
    }
}

void popLightBlocks(vector<vector<int>>& board) {
    int cnt = 0;    // 블록이 있는 행의 수
    
    for (int i=0; i<2; i++) {
        for (int j=0; j<4; j++) {
            if (board[i][j]) {
                cnt++;
                break;
            }
        }
    }
    
    // 행의 수만큼 아래로 이동
    if (cnt > 0) {
        for (int i=5-cnt; i>=0; i--) {
            for (int j=0; j<4; j++) {
                board[i+cnt][j] = board[i][j];
                board[i][j] = false;
            }
        }    
    }
}

void query(int t, int x, int y) {
    auto blocks = getBlocks(t, x, y);
    
    applyGravity(blocks, green);
    applyGravity(toBlueBlocks(blocks), blue);
    
    popRow(green);
    popRow(blue);
    
    popLightBlocks(green);
    popLightBlocks(blue);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N; cin >> N;
    for (int i=0; i<N; i++) {
        int t, x, y;
        cin >> t >> x >> y;
        query(t, x, y);
    }
    
    for (int i=0; i<6; i++) {
        for (int j=0; j<4; j++) {
            if (green[i][j]) tile_cnt++;
            if (blue[i][j]) tile_cnt++;
        }
    }
    cout << score << "\n";
    cout << tile_cnt << "\n";

    return 0;
}
