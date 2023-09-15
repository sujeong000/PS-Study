#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int r, c, dir;  
};

const int MAX_N = 501;
const int UP = 0, RIGHT = 1, DOWN = 2, LEFT = 3;

bool visited[MAX_N][MAX_N][4];
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

Node calcNextNode(Node node, const vector<string>& grid) {
    int N = grid.size();
    int M = grid[0].size();
    
    int nr, nc, ndir;
    
    switch (grid[node.r][node.c]) {
        case 'L':
            ndir = (node.dir + 3) % 4;
            break;
        case 'R':
            ndir = (node.dir + 1) % 4;
            break;
        case 'S':
            ndir = node.dir;
            break;
    }
    
    nr = (node.r + dr[ndir] + N) % N;
    nc = (node.c + dc[ndir] + M) % M;
    
    return {nr, nc, ndir};
}

int DFS(Node node, const vector<string>& grid) {
    if (visited[node.r][node.c][node.dir]) return 0;
    
    visited[node.r][node.c][node.dir] = true;
    return DFS(calcNextNode(node, grid), grid) + 1;
}

vector<int> findAllCycles(const vector<string>& grid) {
    vector<int> ret;
    
    int N = grid.size();
    int M = grid[0].size();
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            for (int k=0; k<4; k++) {
                if (visited[i][j][k]) continue;
                ret.push_back(DFS({i, j, k}, grid));
            }
        }
    }
    
    sort(ret.begin(), ret.end());
    
    return ret;
}

vector<int> solution(vector<string> grid) {
    vector<int> answer = findAllCycles(grid);
    return answer;
}
