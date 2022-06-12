#include <iostream>
#include <vector>

using namespace std;

vector<int> playRound(const vector<int>& v, int A, int B) {
    vector<int> ret;
    
    for (int i=0; i<v.size(); i+=2) {
        if (i+1 < v.size()) {
            if (v[i] == A || v[i] == B) ret.push_back(v[i]);
            else if (v[i+1] == A || v[i+1] == B) ret.push_back(v[i+1]);
            else ret.push_back(v[i]);
        }
        else {
            ret.push_back(v[i]);
        }
    }
    
    return ret;
}

int solution(int N, int A, int B) {
    int cnt = 1;
    vector<int> v;
    for (int i=1; i<=N; i++) v.push_back(i);
    
    while (v.size() > 1) {
        for (int i=0; i<v.size()-1; i+=2) {
            if (v[i] == A && v[i+1] == B) {
                return cnt;
            }
        }
        
        v = playRound(v, A, B);
        cnt++;
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int N, Kim, Lim;
    cin >> N >> Kim >> Lim;
    if (Kim > Lim) swap(Kim, Lim);
    
    cout << solution(N, Kim, Lim);

    return 0;
}
