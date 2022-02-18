#include <iostream>

using namespace std;

int INF = 987654321;
int N, M, T;
int disk[50][50];
int new_disk[50][50];
int start[50];
bool did_remove;

void remove_num(int r1, int c1, int r2, int c2) {
    new_disk[r1][c1] = INF;
    new_disk[r2][c2] = INF;
    did_remove = true;
}

void remove_adj() {
    copy(&disk[0][0], &disk[0][0]+2500, &new_disk[0][0]);
    
    did_remove = false;
    int sum = 0;
    int cnt = 0;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if (disk[i][j] == INF) continue;
            
            sum += disk[i][j];
            cnt++;
            
            // j가 i번 원판에서 몇 번째 수인지
            int order = (j - start[i] + M) % M;
            
            // 1. 좌
            if (disk[i][j] == disk[i][(j-1+M)%M]) {
                remove_num(i, j, i, (j-1+M)%M);
            }
            
            // 2. 우
            if (disk[i][j] == disk[i][(j+1)%M]) {
                remove_num(i, j, i, (j+1)%M);
            }
            
            // 3. 안
            if (i != 0 && disk[i][j] == disk[i-1][(start[i-1]+order)%M]) {
                remove_num(i, j, i-1, (start[i-1]+order)%M);
            }
            
            // 4. 밖
            if (i != N-1 && disk[i][j] == disk[i+1][(start[i+1]+order)%M]) {
                remove_num(i, j, i+1, (start[i+1]+order)%M);
            }
        }
    }
    
    if (did_remove) {
        copy(&new_disk[0][0], &new_disk[0][0]+2500, &disk[0][0]);
    }
    else {
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if (disk[i][j] == INF) continue;
                
                if (disk[i][j] * cnt > sum) {
                    disk[i][j]--;
                }
                else if (disk[i][j] * cnt < sum) {
                    disk[i][j]++;
                }
            }
        }
    }
}

void spin(int x, int d, int k) {
    for (int i=x; i<=N; i+=x) {
        if (d == 0) {
            start[i-1] = (start[i-1] - k + M) % M;
        }
        else {
            start[i-1] = (start[i-1] + k) % M;
        }
    }
}

int calc_sum() {
    int sum = 0;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if (disk[i][j] == INF) continue;
            
            sum += disk[i][j];
        }
    }
    
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> N >> M >> T;
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> disk[i][j];
        }
    }
    
    int x, d, k;
    
    for(int i=0; i<T; i++) {
        cin >> x >> d >> k;
        
        spin(x, d, k);
        remove_adj();
    }
    
    cout << calc_sum();

    return 0;
}
