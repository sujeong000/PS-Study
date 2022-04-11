#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 21;

int T, M, N;
int tags[MAX], cases[1 << 21];
string s;

int count_one(int x) {
    int ret = 0;
    
    while (x > 0) {
        ret += (x % 2);
        x /= 2;
    }
    
    return ret;
}

bool cmp(const int a, const int b) {
    int cnta = count_one(a), cntb = count_one(b);
    if (cnta == cntb) return a < b;
    else return cnta < cntb;
}

bool check(int mask) {
    int res = 0;
    
    for (int i=0; i<N; i++) {
        if ((mask & (1 << i)) != 0) res |= tags[i];
    }
    
    return res == ((1 << M) - 1);
}

int bruteforce() {
    for (int i=0; i<(1 << N); i++) cases[i] = i;
    sort(cases, cases+(1 << N), cmp);
    
    for (int i=0; i<(1 << N); i++) {
        if (check(cases[i])) return cases[i];
    }
    
    return 0;
}

void init_testcase() {
    memset(tags, 0, sizeof(tags));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int t = 0;
    cin >> T;
    while (t++ < T) {
        init_testcase();
        
        cin >> M >> N; getline(cin, s);
        for (int i=0; i<N; i++) {
            getline(cin, s);
            
            int idx = 0, x = 0;
            while (idx < s.size()) {
                while (idx < s.size() && s[idx] != ' ') {
                    x *= 10;
                    x += s[idx] - '0';
                    idx++;
                }
                
                tags[i] |= (1 << --x);
                x = 0;
                idx++;
            }
        }
        
        int ans = bruteforce();
        
        cout << "Data Set " << t << ": ";
        for (int i=0; i<N; i++) {
            if ((ans & (1 << i)) != 0) cout << (char)('A'+i) << " ";
        }
        cout << "\n\n";
    }

    return 0;
}
