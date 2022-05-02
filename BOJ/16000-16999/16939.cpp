#include <iostream>
#include <vector>

using namespace std;

vector<int> rubix(25), before(25), after(25);
int top[6][4] = 
{
    {1, 2, 4, 3},
    {9, 10, 12, 11},
    {13, 14, 16, 15},
    {18, 20, 19, 17},
    {5, 6, 8, 7},
    {22, 24, 23, 21}
};
int tside[6][8] =
{
    {13, 14, 5, 6, 17, 18, 21, 22},
    {24, 23, 20, 19, 8, 7, 16, 15},
    {11, 9, 7, 5, 3, 1, 22, 24},
    {2, 4, 6, 8, 10, 12, 23, 21},
    {9, 10, 19, 17, 4, 3, 14, 16},
    {1, 2, 18, 20, 12, 11, 15, 13}
};
int dt[] = {3, 1};
int ds[] = {2, 6};

void copy(vector<int>& v1, vector<int>& v2) {
    for (int i=0; i<v1.size(); i++) {
        v2[i] = v1[i];
    }
}

bool check() {
    for (int i=1; i<25; i+=4) {
        int c = after[i];
        for (int j=1; j<4; j++) {
            if (after[i+j] != c) return false;
        }
    }
    
    return true;
}

int solution() {
    for (int i=0; i<6; i++) {       // 면 6종류
        for (int k=0; k<2; k++) {   // 방향 2종류
            copy(rubix, before);
            copy(rubix, after);
            for (int j=0; j<4; j++) after[top[i][j]] = before[top[i][(j+dt[k])%4]];
            for (int j=0; j<8; j++) after[tside[i][j]] = before[tside[i][(j+ds[k])%8]];
            if (check()) return 1;
        }
    }
    
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    for (int i=1; i<25; i++) cin >> rubix[i];
    cout << solution();

    return 0;
}
