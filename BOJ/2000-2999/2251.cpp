#include <iostream>
#include <string.h>

using namespace std;

const int MAX = 201;

int A, B, C;
int visit[MAX][MAX][MAX];

struct Bottle {
    int capacity, water;
};

// pour(x, y): x에서 y로 붓는다.
pair<Bottle, Bottle> pour(Bottle x, Bottle y) {
    int diff = min(y.capacity-y.water, x.water);
    x.water -= diff;
    y.water += diff;
    
    return {x, y};
}

void DFS(Bottle a, Bottle b, Bottle c) {
    if (visit[a.water][b.water][c.water]) return;
    visit[a.water][b.water][c.water] = true;
    
    pair<Bottle, Bottle> ab = pour(a, b);
    DFS(ab.first, ab.second, c);
    
    pair<Bottle, Bottle> ac = pour(a, c);
    DFS(ac.first, b, ac.second);
    
    pair<Bottle, Bottle> ba = pour(b, a);
    DFS(ba.second, ba.first, c);
    
    pair<Bottle, Bottle> bc = pour(b, c);
    DFS(a, bc.first, bc.second);
    
    pair<Bottle, Bottle> ca = pour(c, a);
    DFS(ca.second, b, ca.first);
    
    pair<Bottle, Bottle> cb = pour(c, b);
    DFS(a, cb.second, cb.first);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> A >> B >> C;
    
    DFS({A, 0}, {B, 0}, {C, C});
    
    for (int i=0; i<=C; i++) {
        for (int j=0; j<=B; j++) {
            if (visit[0][j][i]) {
                cout << i << " ";
                break;
            }
        }
    }

    return 0;
}
