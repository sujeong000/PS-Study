#include <iostream>
#include <vector>

using namespace std;

const int MAX = 21;
int N;
vector<int> K_statements[MAX];
vector<int> L_statements[MAX];

bool validate(int mask) {
    for (int n=0; n<N; n++) {
        bool n_is_lier = (mask & (1 << n)) == 0;
        
        if (!n_is_lier) {
            for (int j=0; j<K_statements[n].size(); j++) {
                bool x_is_lier = (mask & (1 << K_statements[n][j])) == 0;
                if (x_is_lier) return false;
            }
            for (int j=0; j<L_statements[n].size(); j++) {
                bool x_is_lier = (mask & (1 << L_statements[n][j])) == 0;
                if (!x_is_lier) return false;
            }
        }
        else {
            int lie_cnt = 0;
            
            for (int j=0; j<K_statements[n].size(); j++) {
                bool x_is_lier = (mask & (1 << K_statements[n][j])) == 0;
                if (x_is_lier) lie_cnt++;
            }
            for (int j=0; j<L_statements[n].size(); j++) {
                bool x_is_lier = (mask & (1 << L_statements[n][j])) == 0;
                if (!x_is_lier) lie_cnt++;
            }
            
            if (lie_cnt == 0) return false;
        }
    }
    
    return true;
}

int bruteforce() {
    for (int i=0; i<(1<<N); i++) {
        if (validate(i)) return i;
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    
    int K, L, x;
    
    for (int i=0; i<N; i++) {
        cin >> K;
        
        for (int j=0; j<K; j++) {
            cin >> x;
            K_statements[i].push_back(x-1);
        }
        
        cin >> L;
        
        for(int j=0; j<L; j++) {
            cin >> x;
            L_statements[i].push_back(x-1);
        }
    }
    
    int result = bruteforce();
    
    for (int i=0; i<N; i++) {
        if ((result & (1 << i)) != 0) cout << "true\n";
        else cout << "false\n";
    }

    return 0;
}
