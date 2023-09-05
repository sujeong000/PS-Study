#include <string>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iostream>

using namespace std;

const int MAX = 102;

int N;
int cache[MAX][MAX];
int childrenIdx[MAX];
vector<int> children[MAX];
vector<int> leafOrder;
int cnt[MAX];

// numbers[i]: i라는 숫자를 cnt[i]개의 123으로 나눈 결과
vector<int> numbers[MAX];

// x라는 숫자를 k개의 1, 2, 3으로 쪼갤 수 있는가
int dp(int x, int k) {
    if (k > x) return 0;
    if (k == 0) return x == 0 ? 1 : 0;
    
    int& ret = cache[x][k];
    if (ret != -1) return ret;
    
    ret = 0;
    for (int i=1; i<=3; i++) {
        if (x < i) break;
        ret = max(ret, dp(x-i, k-1));
    }
    
    return ret;
}

// 다음 숫자를 떨어트렸을 경우 도달하는 리프 노드의 번호
int calcLeaf() {
    int curr = 1;
    
    while (children[curr].size() > 0) {
        curr = children[curr][childrenIdx[curr]++ % children[curr].size()];
    }
    
    return curr;
}

// x라는 숫자를 k개의 123으로 나누기, 단 사전순으로 제일 빠르게
void devide123(int x, int k, vector<int>& result) {
    if (k == 0) return;
    
    for (int i=1; i<=3; i++) {
        if (i > x) continue;
        if (dp(x-i, k-1)) {
            result.push_back(i);
            devide123(x-i, k-1, result);
            break;
        }
    }
}

// t초에 target을 만들 수 있는가
bool check(int t, vector<int>& target) {
    int newLeaf = calcLeaf();
    leafOrder.push_back(newLeaf);
    cnt[newLeaf] += 1;
    
    for (int i=1; i<=N; i++) {
        // target을 cnt개의 123으로 만들 수 있어야 함
        if (!dp(target[i-1], cnt[i])) {
            return false;
        }
    }
    
    return true;
}

vector<int> calcAnswer(vector<int>& target) {
    vector<int> ret;
    int totalLen = leafOrder.size();
    vector<int> leafOrderIndex(totalLen);   // 몇 번째 leafOrder[i]인지
    vector<int> leafOrderCnt(N+1);          // 지금까지 몇 개의 leafOrder[i]가 나왔는지
    
    for (int i=0; i<totalLen; i++) {
        leafOrderIndex[i] = leafOrderCnt[leafOrder[i]]++;
    }
    
    for (int i=1; i<=N; i++) {
        if (target[i-1] == 0) continue;
        devide123(target[i-1], leafOrderCnt[i], numbers[i]);
    }
    
    for (int i=0; i<totalLen; i++) {
        int x = numbers[leafOrder[i]][leafOrderIndex[i]];
        ret.push_back(x);
    }
    
    return ret;
}

vector<int> solution(vector<vector<int>> edges, vector<int> target) {
    N = target.size();
    vector<int> answer;
    
    for (auto edge: edges) {
        int parent = edge[0];
        int child = edge[1];
        children[parent].push_back(child);
    }
    
    for (int i=1; i<=N; i++) {
        sort(children[i].begin(), children[i].end());
    }
    
    memset(cache, -1, sizeof(cache));
    
    int t = 0;
    while (t < MAX*MAX && !check(t, target)) {
        t++;
    }
    
    if (t == MAX*MAX) answer = {-1};
    else answer = calcAnswer(target);
    
    return answer;
}
