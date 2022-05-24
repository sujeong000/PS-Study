#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MAX = 1000001;

string S;
vector<int> pos[MAX];   // 부분문자열 S[...(i-1)]의 등장 위치
int maxN[MAX];          // 부분문자열 S[...(i-1)]의 n의 최대값

vector<int> getPartialMatch(const string& N) {
    int m = N.size();
    vector<int> pi(m, 0);
    
    int begin = 1, matched = 0;
    while (begin+matched < m) {
        if (N[begin+matched] == N[matched]) {
            matched++;
            pi[begin+matched-1] = matched;
        }
        else {
            if (matched == 0) begin++;
            else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }
    
    return pi;
}

void solution() {
    int N = S.size();
    vector<int> pi = getPartialMatch(S);
    
    for (int i=0; i<N; i++) {
        int suffix = pi[i];
        int prefix = (i+1) - pi[i];
        int n = suffix/prefix;
        if (suffix % prefix == 0 && n > 0) {
            cout << i+1 << " " << n+1 << "\n";
        } 
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> S;
    
    solution();

    return 0;
}
