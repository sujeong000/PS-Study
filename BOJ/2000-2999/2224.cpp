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

const int INF = 987654321;

int N;
int dist[52][52];
vector<pii> ans;

int toInt(char c) {
    if (c <= 'Z') return c - 'A';
    else return c - 'a' + 26;
}

char toChar(int x) {
    if (x < 26) return 'A' + x;
    else return 'a' + x - 26;
}

void floydWarshall() {
    for (int k=0; k<52; k++) {
        for (int i=0; i<52; i++) {
            for (int j=0; j<52; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
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
    for (int i=0; i<52; i++) {
        for (int j=0; j<52; j++) {
            dist[i][j] = INF;
        }
    }
    for (int i=0; i<N; i++) {
        getline(cin, temp);
        p = toInt(temp[0]);
        q = toInt(temp[5]);
        dist[p][q] = 1;
    }
    
    floydWarshall();
    
    for (int i=0; i<52; i++) {
        for (int j=0; j<52; j++) {
            if (dist[i][j] == INF || i == j) continue;
            ans.push_back({i, j});
        }
    }
    
    cout << ans.size() << "\n";
    for (auto prop: ans) {
        cout << toChar(prop.first) << " => " << toChar(prop.second) << "\n";
    }
    
    return 0;
}
