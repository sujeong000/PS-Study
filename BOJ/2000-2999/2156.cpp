#include <iostream>
#include <cstring>

using namespace std;

int N;
int arr[10001];
int cache[10001][4];

int dp(int idx, int combo) {
	if (idx == N) return 0;

	int& ret = cache[idx][combo];
	if (ret != -1) return ret;

	ret = dp(idx + 1, 0);
	if(combo < 2)
		ret = max(arr[idx] + dp(idx + 1, combo + 1), ret);

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	memset(cache, -1, sizeof(cache));

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	cout << dp(0, 0);
}
