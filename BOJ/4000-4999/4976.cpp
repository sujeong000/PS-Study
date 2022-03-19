#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;

int N, W, D;
vector<piii> pieces;    // pieces[i] = {priority, {width, detph}}
int areas[1050];

int area(pii piece) {
    return piece.first * piece.second;
}

pair<pii, pii> cut(pii piece, int s) {
    int w = piece.first, d = piece.second;
    
    s %= (2 * (w+d));
    if (w+d <= s && s <= 2*w+d) s = 2*w+d - s;
    else if (2*w+d < s) s = w + 2*(w+d) - s;
    
    if (s < w) return {{s, d}, {w-s, d}};
    else return {{w, w+d-s}, {w, s-w}};
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    while (true) {
        cin >> N >> W >> D;
        if (N + W + D == 0) break;
        
        pieces.clear();
        pieces.push_back({0, {W, D}});
        
        int p, s;
        
        for (int i=0; i<N; i++) {
            cin >> p >> s;
            
            pair<pii, pii> two_pieces = cut(pieces[p-1].second, s);
            pii piece1 = two_pieces.first;
            pii piece2 = two_pieces.second;
            if (area(piece1) > area(piece2)) swap(piece1, piece2);
            
            pieces[p-1] = {2*i, piece1};
            pieces.push_back({2*i+1, piece2});
            
            sort(pieces.begin(), pieces.end());
        }
        
        for (int i=0; i<pieces.size(); i++) areas[i] = area(pieces[i].second);
        sort(areas, areas+pieces.size());
        
        for (int i=0; i<pieces.size(); i++) cout << areas[i] << " ";
        cout << "\n";
    }

    return 0;
}
