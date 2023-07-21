#include <string>
#include <vector>
#include <iostream>

using namespace std;

const int SIZE = 51;
const string UPDATE = "UPDATE", MERGE = "MERGE", UNMERGE = "UNMERGE", PRINT = "PRINT";

struct Cell {
    int r, c;
    
    Cell(int r=0, int c=0) : r(r), c(c) { }
    
    bool operator==(const Cell& cell) const {
        return r == cell.r && c == cell.c;
    }
    
    bool operator!=(const Cell& cell) const {
        return !(r == cell.r && c == cell.c);
    }
};

string board[SIZE][SIZE];
Cell parent[SIZE][SIZE];

/*
    유니온파인드
*/

Cell find(Cell x) {
    if (parent[x.r][x.c] == x) return x;
    return parent[x.r][x.c] = find(parent[x.r][x.c]);
}

void merge(Cell a, Cell b) {
    Cell pa = find(a);
    Cell pb = find(b);
    
    if (pa == pb) return;
    
    // a를 기준으로 머지
    parent[pb.r][pb.c] = pa;
}

void unmerge(Cell x) {
    parent[x.r][x.c] = x;
}

/*
    쿼리 함수
*/

void update(int r, int c, string value) {
    Cell p = find(Cell(r, c));
    board[p.r][p.c] = value;
}

void update(string value1, string value2) {
    for (int i=1; i<SIZE; i++) {
        for (int j=1; j<SIZE; j++) {
            Cell p = find(Cell(i, j));
            if (board[p.r][p.c] != value1) continue;
            board[p.r][p.c] = value2;
        }
    }
}

void merge(int r1, int c1, int r2, int c2) {
    Cell p1 = find(Cell(r1, c1));
    Cell p2 = find(Cell(r2, c2));
    
    merge(p1, p2);
    
    if (board[p1.r][p1.c] == "") board[p1.r][p1.c] = board[p2.r][p2.c];
}

void unmerge(int r, int c) {
    Cell p = find(Cell(r, c));
    vector<Cell> merged_cells;
    
    for (int i=1; i<SIZE; i++) {
        for (int j=1; j<SIZE; j++) {
            Cell temp = Cell(i, j);
            if (p != find(temp)) continue;
            merged_cells.push_back(temp);
        }
    }
    
    board[r][c] = board[p.r][p.c];
    
    for (auto cell: merged_cells) {
        unmerge(cell);
        if (cell != Cell(r, c)) board[cell.r][cell.c] = "";
    }
}

string print(int r, int c) {
    Cell p = find(Cell(r, c));
    string& ret = board[p.r][p.c];
    
    if (ret.size() == 0) return "EMPTY";
    else return ret;
}

vector<string> split(string s) {
    vector<string> ret;
    string temp = "";
    
    for (char c: s) {
        if (c == ' ') {
            ret.push_back(temp);
            temp = "";
        }
        else {
            temp += c;
        }
    }
    
    if (temp.size() > 0) ret.push_back(temp);
    
    return ret;
}

void query(string cmd, vector<string>& answer) {
    vector<string> splitted_cmd = split(cmd);
    string cmd_type = splitted_cmd[0];
    
    if (cmd_type == UPDATE) {
        if (splitted_cmd.size() == 4) {
            int r = stoi(splitted_cmd[1]);
            int c = stoi(splitted_cmd[2]);
            string value = splitted_cmd[3];
            update(r, c, value);
        }
        else {
            string value1 = splitted_cmd[1];
            string value2 = splitted_cmd[2];
            update(value1, value2);
        }
    }
    else if (cmd_type == MERGE) {
        int r1 = stoi(splitted_cmd[1]);
        int c1 = stoi(splitted_cmd[2]);
        int r2 = stoi(splitted_cmd[3]);
        int c2 = stoi(splitted_cmd[4]);
        merge(r1, c1, r2, c2);
    }
    else if (cmd_type == UNMERGE) {
        int r = stoi(splitted_cmd[1]);
        int c = stoi(splitted_cmd[2]);
        unmerge(r, c);
    }
    else {
        int r = stoi(splitted_cmd[1]);
        int c = stoi(splitted_cmd[2]);
        answer.push_back(print(r, c));
    }
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    // 유니온파인드 초기화
    for (int i=0; i<SIZE; i++) {
        for (int j=0; j<SIZE; j++) {
            parent[i][j] = Cell(i, j);
        }
    }
    
    for (auto command: commands) {
        query(command, answer);
    }
    
    return answer;
}
