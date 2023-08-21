#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
#include <string.h>
#include <string>
#include <math.h>
#include <random>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<char, int> pci;

int N;
bool adj[52][52];
bool visited[52];
vector<pii> ans;

int toInt(char c) {
    if (c <= 'Z') return c - 'A';
    else return c - 'a' + 26;
}

char toChar(int x) {
    if (x < 26) return 'A' + x;
    else return 'a' + x - 26;
}

void dfs(int curr) {
    visited[curr] = true;
    
    for (int i=0; i<52; i++) {
        if (!adj[curr][i] || visited[i]) continue;
        dfs(i);
    }
}

void findQ(int p) {
    for (int i=0; i<52; i++) {
        visited[i] = false;
    }
    
    dfs(p);
    
    for (int q=0; q<52; q++) {
        if (!visited[q] || q == p) continue;
        ans.push_back({p, q});
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string temp;
    int p, q;
    
    cin >> N;
    cin.ignore();
    for (int i=0; i<N; i++) {
        getline(cin, temp);
        p = toInt(temp[0]);
        q = toInt(temp[5]);
        adj[p][q] = true;
    }
    
    for (int i=0; i<52; i++) {
        findQ(i);
    }
    
    cout << ans.size() << "\n";
    for (auto prop: ans) {
        cout << toChar(prop.first) << " => " << toChar(prop.second) << "\n";
    }
    
    return 0;
}
