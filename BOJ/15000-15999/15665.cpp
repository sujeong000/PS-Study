#include <iostream>
#include <set>

using namespace std;

int N, M;
int sequence[7];
set<int> cands;

void printAnswer() {
    for (int i=0; i<M; i++) cout << sequence[i] << " ";
    cout << "\n";
}

void backtrack(int cnt) {
    if (cnt == M) {
        printAnswer();
        return;
    }
    
    for (auto cand: cands) {
        sequence[cnt] = cand;
        backtrack(cnt + 1);
    }
}

int main() {
    cin >> N >> M;
    for (int i=0; i<N; i++) {
        int temp; cin >> temp;
        cands.insert(temp);
    }
    
    backtrack(0);
    
    return 0;
}
