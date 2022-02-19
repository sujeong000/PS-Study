#include <iostream>
#include <queue>
#include <map>

using namespace std;

int initial_state;
map<int, bool> visit;
int U = 0, D = 1, L = 2, R = 3;

int find_zero(int state) {
    int power = 1;
    
    for(int i=0; i<9; i++, power *= 10) {
        if (state / power % 10 == 0) {
            return i;
        }
    }
    
    return -1;
}

int find_nth_num(int state, int n) {
    int power = 1;
    
    for(int i=0; i<n; i++) power *= 10;
    
    return state / power % 10;
}

int make_nth_num_k(int state, int n, int k) {
    int power = 1;
    
    for(int i=0; i<n; i++) power *= 10;
    
    return state - (state / power % 10 * power) + (power * k);
}

int move(int state, int d) {
    int zero_pos = find_zero(state);
    int target_pos;
    
    if (d == U) target_pos = zero_pos + 3;    
    else if (d == D) target_pos = zero_pos - 3;
    else if (d == L) target_pos = zero_pos + 1;
    else target_pos = zero_pos - 1;
    
    int remove_target = make_nth_num_k(state, target_pos, 0);
    
    int target_num = find_nth_num(state, target_pos);
    int move_target_to_zero_pos = make_nth_num_k(remove_target, zero_pos, target_num);
    
    return move_target_to_zero_pos;
}

int BFS(int start) {
    queue<pair<int, int>> q;
    
    visit[start] = true;
    q.push({start, 0});
    
    while (!q.empty()) {
        int curr = q.front().first;
        int dist = q.front().second;
        q.pop();
        
        if (curr == 123456780) return dist;
        
        int zero_pos = find_zero(curr);
        
        vector<int> adj;
        
        // 위에거 아래로
        if (zero_pos < 6) adj.push_back(move(curr, U));
        
        // 아래거 위로
        if (zero_pos > 2) adj.push_back(move(curr, D));
        
        // 왼쪽거 오른쪽으로
        if (zero_pos % 3 != 2) adj.push_back(move(curr, L));
        
        // 오른쪽거 왼쪽으로
        if (zero_pos % 3 != 0) adj.push_back(move(curr, R));
        
        for(int i=0; i<adj.size(); i++) {
            if (visit.find(adj[i]) == visit.end()) {
                visit[adj[i]] = true;
                q.push({adj[i], dist+1});
            }
        }
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int x;
    int power = 100000000;
    
    for(int i=0; i<9; i++, power /=10) {
        cin >> x;
        initial_state += power * x;
    }
    
    cout << BFS(initial_state);

    return 0;
}
