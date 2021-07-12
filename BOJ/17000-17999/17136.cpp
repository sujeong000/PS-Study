#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <cmath>
#include <cstring>
#include <string>
#include <bitset>
#include <stack>

using namespace std;

int board[10][10];
int cnt;
const int INF = 987654321;

bool check(int r, int c, int n) {
	if (r + n - 1 >= 10) return false;
	if (c + n - 1 >= 10) return false;

	for (int i = r; i < r + n; i++) {
		for (int j = c; j < c + n; j++) {
			if (board[i][j] == 0) return false;
		}
	}

	return true;
}

void change(int r, int c, int n, int val) {
	for (int i = r; i < r + n; i++) {
		for (int j = c; j < c + n; j++) {
			board[i][j] = val;
		}
	}
}

// r, c위치부터 마지막까지 채울때 필요한 최소 색종이 개수
// n은 현재 채운 칸 수, used는 현재 사용한 i*i사이즈 색종이 개수
int fill(int r, int c, int n, vector<int> used) {
	if (n == cnt) return 0;	// 남은 칸이 없으면 끝
	if (r == 10) return INF;	// 남은 칸이 있는데 모든 칸을 지나왔으면 불가능

	// 다음칸의 행, 열
	int next = r * 10 + c + 1;
	int nextr = next / 10, nextc = next % 10;

	int ret = INF;
	// 현재 칸이 1인경우
	if (board[r][c] == 1) {
		// 현재 위치에 1*1부터 5*5 사이즈까지 다 놓아본다
		for (int i = 1; i <= 5; i++) {
			// i*i 사이즈 색종이가 남아있나
			if (used[i - 1] == 5) continue;

			// i*i 사이즈를 놓을 수 있는가
			if (check(r, c, i)) {
				// r, c칸 부터 i*i사이즈 색종이를 붙인다
				change(r, c, i, 0);
				n += i * i;
				used[i - 1]++;

				// 다음 칸으로 이동
				ret = min(ret, fill(nextr, nextc, n, used) + 1);

				// 붙였던 색종이 제거
				used[i - 1]--;
				n -= i * i;
				change(r, c, i, 1);
			}
			else break;
		}
	}
	// 현재 칸이 0인 경우
	else {
		ret = fill(nextr, nextc, n, used);
	}

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cin >> board[i][j];
			if (board[i][j] == 1) cnt++;
		}
	}

	vector<int> used = { 0, 0, 0, 0, 0 };
	int ans = fill(0, 0, 0, used);

	if (ans == INF) cout << -1;
	else cout << ans;


	return 0;
}
