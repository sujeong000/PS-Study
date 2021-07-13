#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int isPalin[2500][2500]; // isPalin(i, j) : s[i:j]가 팰린드롬인가
int cache[2500]; // cache[i] : s[i:]을 팰린드롬 분할할 때 분할 개수의 최솟값
string s;
int len;

/* 부분문자열 s[start:end]가 팰린드롬인가 */
int palin(int start, int end) {
	// 기저 사례
	if (start >= end) return 1;
	
	// 메모이제이션
	int& ret = isPalin[start][end];
	if (ret != -1) return ret;

	if (s[start] != s[end]) ret = 0;
	else ret = palin(start + 1, end - 1);

	return ret;
}

/* s[start:] 를 팰린드롬 분할할 때 분할 개수의 최솟값 */
int dp(int start) {
	// 기저 사례
	if (start == len) return 0;

	// 메모이제이션
	int& ret = cache[start];
	if (ret != -1) return ret;

	ret = 987654321;

	// s[start:end]로 자르고 s[end+1:]에 대해 다시 또 분할
	for (int end = start; end < len; end++) {
		if (palin(start, end))	// 팰린드롬일 때만 자를 수 있음
			ret = min(ret, 1 + dp(end + 1));
	}

	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	len = s.length();

	memset(isPalin, -1, sizeof(isPalin));
	memset(cache, -1, sizeof(cache));

	cout << dp(0);
}
