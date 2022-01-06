#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int N;
vector<int> adjacents[1000001];
vector<int> reorderedAdjacents[1000001];
int reorderedIndex[1000001];
bool visit[1000001];
int cnt = 1;

void dfs(int index) {
    visit[index] = true;
    reorderedIndex[index] = cnt++;
    
    for(int i = 0; i < adjacents[index].size(); i++) {
        int adjacent = adjacents[index][i];
        if (!visit[adjacent]) {
            dfs(adjacent);
        }
    }
}

void reorder() {
    dfs(1);
    
    for(int i=1; i <= N; i++) {
        for(int j=0; j < adjacents[i].size(); j++) {
            reorderedAdjacents[reorderedIndex[i]].push_back(reorderedIndex[adjacents[i][j]]);
        }
    } 
}

int INF = 987654321;
int cache[2][1000001];

int dp(int idx, int isParentEarly) {
	if (idx != 1 && reorderedAdjacents[idx].size() == 1) {
	    return !isParentEarly;
	}

	int& ret = cache[isParentEarly][idx];
	if (ret != INF) return ret;

	int early = 1;
	int noEarly = 0;
	for(int i = 0; i < reorderedAdjacents[idx].size(); i++) {
	    int adjacent = reorderedAdjacents[idx][i];
	    if (adjacent > idx) {
	        early += dp(adjacent, true);
	        noEarly += dp(adjacent, false);
	    }
	}
	
	if (isParentEarly) {
	    ret = min(early, noEarly);
	} else {
	    ret = early;
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 1000001; i++) {
	    for (int j = 0; j < 2; j++) {
	        cache[j][i] = INF;
	    }
	}

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int A, B;
		cin >> A >> B;
		adjacents[A].push_back(B);
		adjacents[B].push_back(A);
	}
	
	reorder();

	cout << dp(1, 1);
}
