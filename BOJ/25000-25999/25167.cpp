#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, string> pis;
const int WRONG = 0, SOLVE = 1;

int N, M, P;
map<string, int> record[101][2];
map<string, int> score;
string players[101];

int time_to_int(string t) {
    int ret = 0;
    
    int w[5] = {600, 60, 0, 10, 1};
    for (int i=0; i<5; i++) {
        if (i == 2) continue;
        ret += (t[i] - '0') * w[i];
    }
    
    return ret;
}

bool check_record(int n, int res, string name) {
    return record[n][res].find(name) != record[n][res].end();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> P;
    
    string name;
    
    for (int i=0; i<M; i++) {
        cin >> players[i];
        score[players[i]] = 0;
    }
    
    int pnum;
    string t, r;
    
    for (int i=0; i<P; i++) {
        cin >> pnum >> t >> name >> r;
        int res = (r[0] == 'w') ? WRONG : SOLVE;
        
        if (check_record(pnum, SOLVE, name)) continue;
        if (!check_record(pnum, res, name)) record[pnum][res][name] = time_to_int(t);
    }
    
    for (int i=1; i<=N; i++) {
        vector<pis> v;
        
        for (int j=0; j<M; j++) {
            string player = players[j];
            
            if (!check_record(i, WRONG, player)) {
                score[player] += M+1;
            }
            else {
                if (!check_record(i, SOLVE, player)) {
                    score[player] += M;
                }
                else {
                    int t = record[i][SOLVE][player] - record[i][WRONG][player];
                    v.push_back({t, player});
                }
            }
        }
        
        sort(v.begin(), v.end());
        
        for (int j=0; j<v.size(); j++) {
            string name = v[j].second;
            score[name] += j+1;
        }
    }
    
    vector<pis> v;
    for (int i=0; i<M; i++) v.push_back({score[players[i]], players[i]});
    sort(v.begin(), v.end());
    for (int i=0; i<M; i++) cout << v[i].second << "\n";

    return 0;
}
