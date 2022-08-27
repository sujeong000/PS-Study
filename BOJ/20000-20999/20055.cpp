#include <iostream>
#include <vector>

using namespace std;

int N, K;
int A[200];
int start;
vector<int> robots;
int robot_cnt[200];

bool checkFinish() {
    int cnt = 0;
    
    for (int i=0; i<2*N; i++) {
        if (A[i] == 0) cnt++;    
    }
    
    return cnt >= K;
}

void addNewRobot() {
    if (A[start] != 0) {
        robots.push_back(start);
        robot_cnt[start]++;
        A[start]--;
    }
}

void moveRobots() {
    vector<int> new_robots;
    int end = (start+N-1)%(2*N);
    
    for (auto pos: robots) {
        int npos = (pos+1) % (2*N);
        
        if (robot_cnt[npos] == 0 && A[npos] >= 1) {
            robot_cnt[pos]--;
            new_robots.push_back(npos);
            robot_cnt[npos]++;
            A[npos]--;
            
            // 내리는 위치에 도달하면 그 즉시 내린다
            if (npos == end) {
                new_robots.pop_back();
                robot_cnt[npos]--;
            }
        }
        else {
            // 이동할 수 없다면 가만히 있는다
            new_robots.push_back(pos);   
        }
    }
    
    robots = new_robots;
}

void rotate() {
    start = (start-1 + 2*N) % (2*N);
    int end = (start+N-1) % (2*N);
    vector<int> new_robots;
    
    for (auto pos: robots) {
        new_robots.push_back(pos);
        
        // 내리는 위치에 도달하면 그 즉시 내린다
        if (pos == end) {
            new_robots.pop_back();
            robot_cnt[pos]--;
        }
    }
    
    robots = new_robots;
}

int simulate() {
    for (int step=1;;step++) {
        rotate();
        moveRobots();
        addNewRobot();
        if (checkFinish()) return step;
    }
    
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    for (int i=0; i<2*N; i++) cin >> A[i];
    
    cout << simulate();

    return 0;
}
