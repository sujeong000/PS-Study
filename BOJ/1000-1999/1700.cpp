#include <iostream>
#include <queue>
#include <string.h>

using namespace std;

typedef pair<int, int> pii;

const int MAX = 101;
int N, K, cnt;
int schedule[MAX], multitap[MAX];
queue<int> appear[MAX];

int search(int n) {
    int empty = -1;
    int existing = -1;
    int remove_target = -1;
    
    for (int i=0; i<N; i++) {
        if (multitap[i] == n) {
            return i;
        }
        else if (multitap[i] != -1){
            // 가장 나중에 필요한 것을 뽑는다.
            if (remove_target == -1 || appear[multitap[remove_target]].front() < appear[multitap[i]].front()) {
                remove_target = i;
            }
        }
        else {
            empty = i;
        }
    }
    
    if (empty != -1) return empty;
    else return remove_target;
}

int simulate() {
   int cnt = 0;
    
    for (int i=0; i<K; i++) {
        int curr = schedule[i];
        appear[curr].pop();
        
        int pos = search(curr);
        if (multitap[pos] != -1 && multitap[pos] != curr) cnt++;  
        multitap[search(curr)] = curr;
    }
    
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> K;
    
    for (int i=0; i<K; i++) {
        cin >> schedule[i];
        appear[schedule[i]].push(i);
    }
    
    for (int i=1; i<=K; i++) appear[i].push(987654321);
    memset(multitap, -1, sizeof(multitap));
    
    cout << simulate();

    return 0;
}
