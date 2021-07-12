#include <iostream>
#include <cstring>

using namespace std;

int N;
int cache[10][101];

// n으로 끝나는 길이 len짜리 계단수 개수
int dp(int n, int len) {
	if (len == 1) return (n != 0);

	int& ret = cache[n][len];
	if (ret != -1) return ret;

	if (n == 0) ret = dp(1, len - 1);
	else if (n == 9) ret = dp(8, len - 1);
	else ret = dp(n - 1, len - 1) + dp(n + 1, len - 1);

	return ret = ret % 1000000000;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	memset(cache, -1, sizeof(cache));

	cin >> N;

	int ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += dp(i, N);
		ans %= 1000000000;
	}

	cout << ans;
}
