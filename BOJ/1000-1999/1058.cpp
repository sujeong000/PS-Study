#include <iostream>

using namespace std;

int N;
bool friends[51][51];

bool isFriend(int a, int b) {
    if (a == b) return false;
    if (friends[a][b]) return true;
    for (int c=0; c<N; c++) {
        if (friends[a][c] && friends[b][c]) return true;
    }
    
    return false;
}

int count2Friends(int p) {
    int ret = 0;
    
    for (int i=0; i<N; i++) {
        if (isFriend(p, i)) ret++;
    }
    
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N;
    
    string S;
    for (int i=0; i<N; i++) {
        cin >> S;
        for (int j=0; j<N; j++) {
            friends[i][j] = S[j] == 'Y';
        }
    }
    
    int max2Friends = 0;
    for (int i=0; i<N; i++) {
        max2Friends = max(max2Friends, count2Friends(i));
    }
    
    cout << max2Friends;

    return 0;
}
