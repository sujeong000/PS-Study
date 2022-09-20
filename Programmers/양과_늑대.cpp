#include <string>
#include <vector>
#include <iostream>
#include <string.h>

using namespace std;
const int SHEEP = 0, WOLF = 1;

int N;
vector<int> children[18];

// cand: 다음에 방문할 수 있는 후보지
int dfs(int curr, int sheep, int wolf, int cand, const vector<int>& info) {
    if (wolf >= sheep) return 0;
    
    int ret = sheep;
    
    for (int next=0; next<N; next++) {
        if ((cand & (1 << next)) == 0) continue;
        
        int nsheep = sheep;
        int nwolf = wolf;
        int ncand = cand & ~(1 << next);
        
        if (info[next] == SHEEP) nsheep++;
        else nwolf++;
        for (auto child: children[next]) ncand |= (1 << child);
        
        ret = max(ret, dfs(next, nsheep, nwolf, ncand, info));
    }
    
    return ret;
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    
    N = info.size();
    for (int i=0; i<edges.size(); i++) {
        int p = edges[i][0];
        int c = edges[i][1];
        children[p].push_back(c);
    }
    
    int cand = 0;
    for (auto child: children[0]) cand |= (1 << child);
    answer = dfs(0, 1, 0, cand, info);
    
    return answer;
}
