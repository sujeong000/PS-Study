#include <iostream>

using namespace std;

int N, M;
int rect[51][51];

int find_max_square() {
    int max_size = 0;
    
    for (int i=0; i<N; i++) {
        for (int j=0; j<M; j++) {
            for (int k=0; k<min(N, M); k++) {
                if (k < max_size) continue;
                if (i+k >= N || j+k >= M) break;
                
                int num = rect[i][j];
                if (rect[i][j+k] == num && rect[i+k][j] == num && rect[i+k][j+k] == num) {
                    max_size = max(max_size, k+1);   
                }
            }
        }
    }
    
    return max_size * max_size;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M;
    string s;
    for (int i=0; i<N; i++) {
        cin >> s;
        for (int j=0; j<M; j++) {
            rect[i][j] = s[j] - '0';
        }
    }
    
    cout << find_max_square();

    return 0;
}
