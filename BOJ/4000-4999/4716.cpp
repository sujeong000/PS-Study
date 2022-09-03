#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

struct Team {
    int k, da, db;  
};

int N, A, B;
vector<Team> teams;

bool cmp(const Team& lhs, const Team& rhs) {
    return abs(lhs.da - lhs.db) > abs(rhs.da - rhs.db);
}

void initTestcase() {
    teams.clear();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true) {
        initTestcase();
        
        cin >> N >> A >> B;
        if (N == 0 && A == 0 && B == 0) break;
        
        for (int i=0; i<N; i++) {
            int k, da, db;
            cin >> k >> da >> db;
            teams.push_back({k, da, db});
        }
        
        // 반대를 골랐을 때 손해가 큰 순으로
        sort(teams.begin(), teams.end(), cmp);
        
        ll ans = 0;
        
        for (int i=0; i<N; i++) {
            int a, b;
            
            if (teams[i].da < teams[i].db) {
                a = min(A, teams[i].k);
                b = teams[i].k - a;
            }
            else {
                b = min(B, teams[i].k);
                a = teams[i].k - b;
            }
            
            ans += teams[i].da * a + teams[i].db * b;
            A -= a;
            B -= b;
        }
        
        cout << ans << "\n";
    }

    return 0;
}
