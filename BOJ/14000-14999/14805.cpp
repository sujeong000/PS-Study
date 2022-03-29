#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

typedef pair<int, char> pic;

const string IMPOSSIBLE = "IMPOSSIBLE";
int T, N;
int R, O, Y, G, B, V;
char result[1001];

string repeat_string(string s, int cnt) {
    string ret = "";
    for (int i=0; i<cnt; i++) ret += s;
    return ret;
}

string solution() {
    if (G != 0 && R == G) {
        if (R + G == N) return repeat_string("RG", R);
        else return IMPOSSIBLE;
    }
    if (V != 0 && Y == V) {
        if (Y + V == N) return repeat_string("YV", Y);
        else return IMPOSSIBLE;
    }
    if (O != 0 && B == O) {
        if (B + O == N) return repeat_string("BO", B);
        else return IMPOSSIBLE;
    }
    
    R -= G; Y -= V; B -= O;
    N = R + Y + B;
    
    if (R > N/2 || Y > N/2 || B > N/2 || R < 0 || Y < 0 || B < 0) return IMPOSSIBLE;
    else {
        int pos = 0;
        pic primary[3] = {{R, 'R'}, {Y, 'Y'}, {B, 'B'}};
        sort(primary, primary+3);
        
        for (int c=2; c>=0; c--) {
            for (int i=0; i<primary[c].first; i++, pos+=2) {
                if (pos >= N) pos = 1;
                result[pos] = primary[c].second;
            }
        }
        
        string ret = "";
        for (int i=0; i<N; i++) {
            ret += result[i];
            switch (result[i]) {
                case 'R': ret += repeat_string("GR", G); G = 0; break;
                case 'Y': ret += repeat_string("VY", V); V = 0; break;
                case 'B': ret += repeat_string("OB", O); O = 0; break;
            }
        }
        return ret;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> T;
    for (int t=1; t<=T; t++) {
        cin >> N >> R >> O >> Y >> G >> B >> V;
        
        string ans = solution();
        
        cout << "Case #" << t << ": ";
        cout << ans;
        cout << "\n";
    }
    
    return 0;
}
