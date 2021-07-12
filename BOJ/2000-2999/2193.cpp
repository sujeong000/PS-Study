#include <iostream>
#include <cstring>

using namespace std;

int N;
long long cache[2][91];	

// one_or_zero로 시작하고 길이가 len인 이진수중 1이 연속되지 않는 이진수 개수
long long dp(int one_or_zero, int len) {
	if (len == 1) return 1;

	long long& ret = cache[one_or_zero][len];
	if (ret != -1) return ret;

	if (one_or_zero == 0)
		ret = dp(0, len - 1) + dp(1, len - 1);
	else
		ret = dp(0, len - 1);

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	memset(cache, -1, sizeof(cache));

	int N;
	cin >> N;

	cout << dp(1, N);
}
