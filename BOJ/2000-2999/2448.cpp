#include <iostream>

using namespace std;

int N;
char arr[10000][10000];

void fillStar(int row, int col, int size) {
    if (size == 3) {
        arr[row][col+2] = '*';
        arr[row+1][col+1] = '*'; arr[row+1][col+3] = '*';
        for(int i=0; i<5; i++) arr[row+2][col+i] = '*';
    }
    else {
        fillStar(row, col + size/2, size/2);
        fillStar(row+size/2, col, size/2);
        fillStar(row+size/2, col+size, size/2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	
	for(int i=0; i<N; i++) {
	    for(int j=0; j<2*N-1; j++) {
	        arr[i][j] = ' ';
	    }
	}
	
	fillStar(0, 0, N);
	
	for(int i=0; i<N; i++) {
	    for(int j=0; j<2*N-1; j++) {
	        cout << arr[i][j];
	    }
	    cout << "\n";
	}

    return 0;
}
