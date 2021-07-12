#include <iostream>
#include <cstring>

using namespace std;

int N;
int arr[100001];
int cache[100001];

int dp(int idx) {
	if (idx == N) return 0;

	int& ret = cache[idx];
	if (ret != -987654321) return ret;

	ret = arr[idx];
	if (dp(idx + 1) > 0) ret += dp(idx + 1);

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 100001; i++)
		cache[i] = -987654321;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int maxVal = -987654321;
	for (int i = 0; i < N; i++) {
		maxVal = max(maxVal, dp(i));
	}

	cout << maxVal;
}
